#pragma once

#include "webgl2.h"

// 33. https://www.khronos.org/registry/webgl/extensions/EXT_disjoint_timer_query_webgl2/
#ifndef EMSCRIPTEN_GL_EXT_disjoint_timer_query_webgl2
#define EMSCRIPTEN_GL_EXT_disjoint_timer_query_webgl2 1
#define GL_QUERY_COUNTER_BITS_EXT 0x8864
#define GL_TIME_ELAPSED_EXT 0x88BF
#define GL_TIMESTAMP_EXT 0x8E28
#define GL_GPU_DISJOINT_EXT 0x8FBB
WEBGL_APICALL void GL_APIENTRY emscripten_webgl2_queryCounterEXT(GLuint query, GLenum target);
#endif /* EMSCRIPTEN_GL_EXT_disjoint_timer_query_webgl2 */

// 46. https://www.khronos.org/registry/webgl/extensions/WEBGL_draw_instanced_base_vertex_base_instance/
#ifndef EMSCRIPTEN_GL_WEBGL_draw_instanced_base_vertex_base_instance
#define EMSCRIPTEN_GL_WEBGL_draw_instanced_base_vertex_base_instance 1

WEBGL_APICALL void GL_APIENTRY emscripten_glDrawArraysInstancedBaseInstanceWEBGL(
  GLenum mode, GLint first, GLsizei count, GLsizei instanceCount, GLuint baseInstance);

WEBGL_APICALL void GL_APIENTRY emscripten_glDrawElementsInstancedBaseVertexBaseInstanceWEBGL(
  GLenum mode, GLsizei count, GLenum type, const void *offset, GLsizei instanceCount, GLint baseVertex, GLuint baseInstance);

WEBGL_APICALL void GL_APIENTRY glDrawArraysInstancedBaseInstanceWEBGL(
  GLenum mode, GLint first, GLsizei count, GLsizei instanceCount, GLuint baseInstance);

WEBGL_APICALL void GL_APIENTRY glDrawElementsInstancedBaseVertexBaseInstanceWEBGL(
  GLenum mode, GLsizei count, GLenum type, const void *offset, GLsizei instanceCount, GLint baseVertex, GLuint baseInstance);

#endif /* EMSCRIPTEN_GL_WEBGL_draw_instanced_base_vertex_base_instance */

// 47. https://www.khronos.org/registry/webgl/extensions/WEBGL_multi_draw_instanced_base_vertex_base_instance/
#ifndef EMSCRIPTEN_GL_WEBGL_multi_draw_instanced_base_vertex_base_instance
#define EMSCRIPTEN_GL_WEBGL_multi_draw_instanced_base_vertex_base_instance 1

WEBGL_APICALL void GL_APIENTRY emscripten_glMultiDrawArraysInstancedBaseInstanceWEBGL(
  GLenum mode,
  const GLint* firsts __attribute__((nonnull)),
  const GLsizei* counts __attribute__((nonnull)),
  const GLsizei* instanceCounts __attribute__((nonnull)),
  const GLuint* baseInstances __attribute__((nonnull)),
  GLsizei drawCount);

WEBGL_APICALL void GL_APIENTRY emscripten_glMultiDrawElementsInstancedBaseVertexBaseInstanceWEBGL(
  GLenum mode,
  const GLsizei* counts __attribute__((nonnull)),
  GLenum type,
  const GLvoid* const* offsets __attribute__((nonnull)),
  const GLsizei* instanceCounts __attribute__((nonnull)),
  const GLint* baseVertices __attribute__((nonnull)),
  const GLuint* baseInstances __attribute__((nonnull)),
  GLsizei drawCount);

WEBGL_APICALL void GL_APIENTRY glMultiDrawArraysInstancedBaseInstanceWEBGL(
  GLenum mode,
 const GLint* firsts __attribute__((nonnull)),
 const GLsizei* counts __attribute__((nonnull)),
 const GLsizei* instanceCounts __attribute__((nonnull)),
 const GLuint* baseInstances __attribute__((nonnull)),
 GLsizei drawCount);

WEBGL_APICALL void GL_APIENTRY glMultiDrawElementsInstancedBaseVertexBaseInstanceWEBGL(
  GLenum mode,
  const GLsizei* counts __attribute__((nonnull)),
  GLenum type,
  const GLvoid* const* offsets __attribute__((nonnull)),
  const GLsizei* instanceCounts __attribute__((nonnull)),
  const GLint* baseVertices __attribute__((nonnull)),
  const GLuint* baseinstances __attribute__((nonnull)),
  GLsizei drawCount);

#endif /* EMSCRIPTEN_GL_WEBGL_multi_draw_instanced_base_vertex_base_instance */

// 49. https://registry.khronos.org/webgl/extensions/WEBGL_shader_pixel_local_storage/
#ifndef EMSCRIPTEN_GL_WEBGL_shader_pixel_local_storage
#define EMSCRIPTEN_GL_WEBGL_shader_pixel_local_storage 1
#define GL_MAX_PIXEL_LOCAL_STORAGE_PLANES_WEBGL 0x96E0
#define GL_MAX_COLOR_ATTACHMENTS_WITH_ACTIVE_PIXEL_LOCAL_STORAGE_WEBGL 0x96E1
#define GL_MAX_COMBINED_DRAW_BUFFERS_AND_PIXEL_LOCAL_STORAGE_PLANES_WEBGL 0x96E2
#define GL_PIXEL_LOCAL_STORAGE_ACTIVE_PLANES_WEBGL 0x96E3
#define GL_LOAD_OP_ZERO_WEBGL 0x96E4
#define GL_LOAD_OP_CLEAR_WEBGL 0x96E5
#define GL_LOAD_OP_LOAD_WEBGL 0x96E6
#define GL_STORE_OP_STORE_WEBGL 0x96E7
#define GL_PIXEL_LOCAL_FORMAT_WEBGL 0x96E8
#define GL_PIXEL_LOCAL_TEXTURE_NAME_WEBGL 0x96E9
#define GL_PIXEL_LOCAL_TEXTURE_LEVEL_WEBGL 0x96EA
#define GL_PIXEL_LOCAL_TEXTURE_LAYER_WEBGL 0x96EB
#define GL_PIXEL_LOCAL_CLEAR_VALUE_FLOAT_WEBGL 0x96EC
#define GL_PIXEL_LOCAL_CLEAR_VALUE_INT_WEBGL 0x96ED
#define GL_PIXEL_LOCAL_CLEAR_VALUE_UNSIGNED_INT_WEBGL 0x96EE

WEBGL_APICALL void GL_APIENTRY emscripten_glFramebufferTexturePixelLocalStorageWEBGL(
  GLint plane, GLuint backingtexture, GLint level, GLint layer);
WEBGL_APICALL void GL_APIENTRY emscripten_glFramebufferPixelLocalClearValuefvWEBGL(
  GLint plane, const GLfloat value[]);
WEBGL_APICALL void GL_APIENTRY emscripten_glFramebufferPixelLocalClearValueivWEBGL(
  GLint plane, const GLint value[]);
WEBGL_APICALL void GL_APIENTRY emscripten_glFramebufferPixelLocalClearValueuivWEBGL(
  GLint plane, const GLuint value[]);
WEBGL_APICALL void GL_APIENTRY emscripten_glBeginPixelLocalStorageWEBGL(
  GLsizei n, const GLenum loadops[]);
WEBGL_APICALL void GL_APIENTRY emscripten_glEndPixelLocalStorageWEBGL(
  GLsizei n, const GLenum storeops[]);
WEBGL_APICALL void GL_APIENTRY emscripten_glPixelLocalStorageBarrierWEBGL();
WEBGL_APICALL void GL_APIENTRY emscripten_glGetFramebufferPixelLocalStorageParameterfvWEBGL(
  GLint plane, GLenum pname, GLfloat *params);
WEBGL_APICALL void GL_APIENTRY emscripten_glGetFramebufferPixelLocalStorageParameterivWEBGL(
  GLint plane, GLenum pname, GLint *params);

WEBGL_APICALL void GL_APIENTRY glFramebufferTexturePixelLocalStorageWEBGL(
  GLint plane, GLuint backingtexture, GLint level, GLint layer);
WEBGL_APICALL void GL_APIENTRY glFramebufferPixelLocalClearValuefvWEBGL(
  GLint plane, const GLfloat value[]);
WEBGL_APICALL void GL_APIENTRY glFramebufferPixelLocalClearValueivWEBGL(
  GLint plane, const GLint value[]);
WEBGL_APICALL void GL_APIENTRY glFramebufferPixelLocalClearValueuivWEBGL(
  GLint plane, const GLuint value[]);
WEBGL_APICALL void GL_APIENTRY glBeginPixelLocalStorageWEBGL(
  GLsizei n, const GLenum loadops[]);
WEBGL_APICALL void GL_APIENTRY glEndPixelLocalStorageWEBGL(
  GLsizei n, const GLenum storeops[]);
WEBGL_APICALL void GL_APIENTRY glPixelLocalStorageBarrierWEBGL();
WEBGL_APICALL void GL_APIENTRY glGetFramebufferPixelLocalStorageParameterfvWEBGL(
  GLint plane, GLenum pname, GLfloat *params);
WEBGL_APICALL void GL_APIENTRY glGetFramebufferPixelLocalStorageParameterivWEBGL(
  GLint plane, GLenum pname, GLint *params);
#endif /* EMSCRIPTEN_GL_WEBGL_shader_pixel_local_storage */
