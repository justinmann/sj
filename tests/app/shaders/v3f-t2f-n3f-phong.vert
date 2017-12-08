attribute vec3 vertex;
attribute vec2 tex_coord;
attribute vec3 normal;

uniform mediump mat4 projection;
uniform mediump mat4 viewModel;
uniform mediump mat4 normalMat;

varying mediump vec3 normalInterp;
varying mediump vec3 vertPos;
varying mediump vec2 textureCoordinate;

void main() {
    textureCoordinate = tex_coord;
    gl_Position = projection * viewModel * vec4(vertex, 1.0);
    mediump vec4 vertPos4 = viewModel * vec4(vertex, 1.0);
    vertPos = vec3(vertPos4) / vertPos4.w;
    normalInterp = vec3(normalMat * vec4(normal, 0.0));
}
