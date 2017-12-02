/* Freetype GL - A C OpenGL Freetype engine
 *
 * Distributed under the OSI-approved BSD 2-Clause License.  See accompanying
 * file `LICENSE` for more details.
 */

cstruct{
/**
 * Maximum number of attributes per vertex
 *
 * @private
 */
##define MAX_VERTEX_ATTRIBUTE 16


/**
 *  Generic vertex attribute.
 */
typedef struct vertex_attribute_t
{
    /**
     *  atribute name
     */
    GLchar * name;

    /**
     * index of the generic vertex attribute to be modified.
     */
    GLuint index;

    /**
     * Number of components per generic vertex attribute.
     *
     * Must be 1, 2, 3, or 4. The initial value is 4.
     */
    GLint size;

    /**
     *  data type of each component in the array.
     *
     *  Symbolic constants GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT,
     *  GL_UNSIGNED_SHORT, GL_INT, GL_UNSIGNED_INT, GL_FLOAT, or GL_DOUBLE are
     *  accepted. The initial value is GL_FLOAT.
     */
    GLenum type;

    /**
     *  whether fixed-point data values should be normalized (GL_TRUE) or
     *  converted directly as fixed-point values (GL_FALSE) when they are
     *  accessed.
     */
    GLboolean normalized;

    /**
     *  byte offset between consecutive generic vertex attributes.
     *
     *  If stride is 0, the generic vertex attributes are understood to be
     *  tightly packed in the array. The initial value is 0.
     */
    GLsizei stride;

    /**
     *  pointer to the first component of the first attribute element in the
     *  array.
     */
    GLvoid * pointer;

    /**
     * pointer to the function that enable this attribute.
     */
    void ( * enable )(void *);

} vertex_attribute_t;
}cstruct

cdefine{
/**
 * Create an attribute from the given parameters.
 *
 * @param size       number of component
 * @param type       data type
 * @param normalized Whether fixed-point data values should be normalized
                     (GL_TRUE) or converted directly as fixed-point values
                     (GL_FALSE) when they are  accessed.
 * @param stride     byte offset between consecutive attributes.
 * @param pointer    pointer to the first component of the first attribute
 *                   element in the array.
 * @return           a new initialized vertex attribute.
 *
 * @private
 */
vertex_attribute_t *
vertex_attribute_new( GLchar * name,
                      GLint size,
                      GLenum type,
                      GLboolean normalized,
                      GLsizei stride,
                      GLvoid *pointer );



/**
 * Delete a vertex attribute.
 *
 * @param  self a vertex attribute
 *
 */
void
vertex_attribute_delete( vertex_attribute_t * self );


/**
 * Create an attribute from the given description.
 *
 * @param  format Format string specifies the format of a vertex attribute.
 * @return        an initialized vertex attribute
 *
 * @private
 */
  vertex_attribute_t *
  vertex_attribute_parse( char *format );

/**
 * Enable a vertex attribute.
 *
 * @param attr  a vertex attribute
 *
 * @private
 */
  void
  vertex_attribute_enable( vertex_attribute_t *attr );    
}cdefine

cfunction{

#include(<assert.h>)
#include(<string.h>)
#include(<stdlib.h>)
#include(<stdio.h>)

// ----------------------------------------------------------------------------
vertex_attribute_t *
vertex_attribute_new( GLchar * name,
                      GLint size,
                      GLenum type,
                      GLboolean normalized,
                      GLsizei stride,
                      GLvoid *pointer )
{
    vertex_attribute_t *attribute =
        (vertex_attribute_t *) malloc (sizeof(vertex_attribute_t));

    assert( size > 0 );

    attribute->name       = (GLchar *) _strdup( name );
    attribute->index      = -1;
    attribute->size       = size;
    attribute->type       = type;
    attribute->normalized = normalized;
    attribute->stride     = stride;
    attribute->pointer    = pointer;
    return attribute;
}



// ----------------------------------------------------------------------------
void
vertex_attribute_delete( vertex_attribute_t * self )
{
    assert( self );

    free( self->name );
    free( self );
}



// ----------------------------------------------------------------------------
vertex_attribute_t *
vertex_attribute_parse( char *format )
{
    GLenum type = 0;
    int size;
    int normalized = 0;
    char ctype;
    char *name;
    vertex_attribute_t *attr;
    char *p = strchr(format, ':');
    if( p != NULL)
    {
        name = strndup(format, p-format);
        if( *(++p) == '\0' )
        {
            fprintf( stderr, "No size specified for '%s' attribute\n", name );
            free( name );
            return 0;
        }
        size = *p - '0';

        if( *(++p) == '\0' )
        {
            fprintf( stderr, "No format specified for '%s' attribute\n", name );
            free( name );
            return 0;
        }
        ctype = *p;

        if( *(++p) != '\0' )
        {
            if( *p == 'n' )
            {
                normalized = 1;
            }
        }

    }
    else
    {
        fprintf(stderr, "Vertex attribute format not understood ('%s')\n", format );
        return 0;
    }

    switch( ctype )
    {
    case 'b': type = GL_BYTE;           break;
    case 'B': type = GL_UNSIGNED_BYTE;  break;
    case 's': type = GL_SHORT;          break;
    case 'S': type = GL_UNSIGNED_SHORT; break;
    case 'i': type = GL_INT;            break;
    case 'I': type = GL_UNSIGNED_INT;   break;
    case 'f': type = GL_FLOAT;          break;
    default:  type = 0;                 break;
    }


    attr = vertex_attribute_new( name, size, type, normalized, 0, 0 );
    free( name );
    return attr;
}



// ----------------------------------------------------------------------------
void
vertex_attribute_enable( vertex_attribute_t *attr )
{
    if( attr->index == -1 )
    {
        GLint program;
        glGetIntegerv( GL_CURRENT_PROGRAM, &program );
        if( program == 0)
        {
            return;
        }
        attr->index = glGetAttribLocation( program, attr->name );
        if( attr->index == -1 )
        {
            return;
        }
    }
    glEnableVertexAttribArray( attr->index );
    glVertexAttribPointer( attr->index, attr->size, attr->type,
                           attr->normalized, attr->stride, attr->pointer );
}
}cfunction