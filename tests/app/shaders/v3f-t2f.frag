/* Freetype GL - A C OpenGL Freetype engine
 *
 * Distributed under the OSI-approved BSD 2-Clause License.  See accompanying
 * file `LICENSE` for more details.
 */
uniform sampler2D texture;
varying mediump vec2 v_textureCoordinate;

void main()
{
	mediump vec4 color = texture2D(texture, v_textureCoordinate);
    gl_FragColor = vec4(color.r, 1, color.b, 1); 
}
