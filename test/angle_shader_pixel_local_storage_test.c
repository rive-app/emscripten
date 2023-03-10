/*
 * Copyright 2020 The Emscripten Authors.  All rights reserved.
 * Emscripten is available under two separate licenses, the MIT license and the
 * University of Illinois/NCSA Open Source License.  Both these licenses can be
 * found in the LICENSE file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>

#include <webgl/webgl2_ext.h>

#include <GLES3/gl3.h>

GLuint compile_shader(GLenum shaderType, const char *src)
{
  GLuint shader = glCreateShader(shaderType);
  glShaderSource(shader, 1, &src, NULL);
  glCompileShader(shader);

  GLint isCompiled = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
  if (!isCompiled)
  {
    GLint maxLength = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
    char *buf = (char*)malloc(maxLength);
    glGetShaderInfoLog(shader, maxLength, NULL, buf);
    printf("%s\n", buf);
    free(buf);
    return 0;
  }

   return shader;
}

GLuint create_program(GLuint vertexShader, GLuint fragmentShader)
{
   GLuint program = glCreateProgram();
   glAttachShader(program, vertexShader);
   glAttachShader(program, fragmentShader);
   glBindAttribLocation(program, 0, "apos");
   glBindAttribLocation(program, 1, "acolor");
   glLinkProgram(program);
   return program;
}

int main()
{
  EMSCRIPTEN_WEBGL_CONTEXT_HANDLE ctx;
  EMSCRIPTEN_RESULT res;
  EmscriptenWebGLContextAttributes attrs;
  emscripten_webgl_init_context_attributes(&attrs);
  attrs.majorVersion = 2;
  attrs.antialias = 0;
  ctx = emscripten_webgl_create_context("#canvas", &attrs);
  assert(ctx > 0); // Must have received a valid context.
  res = emscripten_webgl_make_context_current(ctx);
  assert(res == EMSCRIPTEN_RESULT_SUCCESS);

  GLboolean extAvailable = emscripten_webgl_enable_ANGLE_shader_pixel_local_storage(ctx);

  if (!extAvailable) {
    EM_ASM({
      xhr = new XMLHttpRequest();
      xhr.open('GET', 'http://localhost:8888/report_result?skipped:%20ANGLE_shader_pixel_local_storage%20is%20not%20supported!');
      xhr.send();
      setTimeout(function() { window.close() }, 2000);
    });
    return 0;
  }

  const int w = 10, h = 10;

  GLuint tex;
  glGenTextures(1, &tex);
  glBindTexture(GL_TEXTURE_2D, tex);
  glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, w, h);

  GLuint fbo;
  glGenFramebuffers(1, &fbo);
  glBindFramebuffer(GL_FRAMEBUFFER, fbo);
  glFramebufferTexturePixelLocalStorageANGLE(0, tex, 0, 0);

  glViewport(0, 0, w, h);

  GLuint vs = compile_shader(GL_VERTEX_SHADER,
  "#version 300 es\n"
  "void main() {"
    "gl_Position.x = (gl_VertexID & 1) == 0 ? -1. : 1.;"
    "gl_Position.y = (gl_VertexID & 2) == 0 ? -1. : 1.;"
    "gl_Position.zw = vec2(0, 1);"
  "}");

  GLuint fs = compile_shader(GL_FRAGMENT_SHADER,
  "#version 300 es\n"
  "#extension GL_ANGLE_shader_pixel_local_storage : require\n"
  "precision lowp float;"
  "uniform vec4 color;"
  "layout(binding=0, rgba8) uniform lowp pixelLocalANGLE pls;"
  "void main() {"
    "vec4 newColor = color + pixelLocalLoadANGLE(pls);"
    "pixelLocalStoreANGLE(pls, newColor);"
  "}");

  GLuint program = create_program(vs, fs);
  glUseProgram(program);
  GLint colorUniLocation = glGetUniformLocation(program, "color");

  glDisable(GL_DITHER);

  GLenum load = GL_LOAD_OP_ZERO_ANGLE;
  glBeginPixelLocalStorageANGLE(1, &load);

  glUniform4f(colorUniLocation, 0, 1, 0, 0);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glPixelLocalStorageBarrierANGLE();

  glUniform4f(colorUniLocation, 0, 0, 0, 1);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  GLenum store = GL_STORE_OP_STORE_ANGLE;
  glEndPixelLocalStorageANGLE(1, &store);

  GLuint readFBO;
  glGenFramebuffers(1, &readFBO);
  glBindFramebuffer(GL_FRAMEBUFFER, readFBO);
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tex, 0);
  glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
  glBlitFramebuffer(0, 0, w, h, 0, 0, w, h, GL_COLOR_BUFFER_BIT, GL_NEAREST);
}
