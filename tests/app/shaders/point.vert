/* Freetype GL - A C OpenGL Freetype engine
 *
 * Distributed under the OSI-approved BSD 2-Clause License.  See accompanying
 * file `LICENSE` for more details.
 */
uniform mediump mat4 viewModel;
uniform mediump mat4 projection;

attribute vec3 vertex;

void main()
{
    gl_Position = projection*(viewModel*vec4(vertex,1.0));
    gl_PointSize = 1.0;
}
