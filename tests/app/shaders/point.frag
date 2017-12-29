/* Freetype GL - A C OpenGL Freetype engine
 *
 * Distributed under the OSI-approved BSD 2-Clause License.  See accompanying
 * file `LICENSE` for more details.
 */

uniform mediump vec3 color;

void main()
{
    gl_FragColor = vec4(color.rgb, 1.0); 
}
