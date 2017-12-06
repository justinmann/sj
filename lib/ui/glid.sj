--cstruct--
typedef struct GLid_td GLid_s;

struct GLid_td {
    GLuint id;
    int refCount;
    UT_hash_handle hh;
};

GLid_s* g_GLids = 0;
--cstruct--

--cdefine--
void _retainGLid(GLuint id);
bool _releaseGLid(GLuint id);
--cdefine--

--cfunction--
void _retainGLid(GLuint id) {
  GLid_s* p;
  HASH_FIND_PTR(g_GLids, &id, p);
  if (p) {
    p->refCount++;
  } else {
    p = (GLid_s*)malloc(sizeof(GLid_s));
    p->id = id;
    p->refCount = 1;
    HASH_ADD_PTR(g_GLids, id, p);    
  }
}

bool _releaseGLid(GLuint id) {
  GLid_s* p;
  HASH_FIND_PTR(g_GLids, &id, p);
  if (p) {
    p->refCount--;
    if (p->refCount == 0) {
      HASH_DEL(g_GLids, p);
      free(p);
    }
    return false;
  }
  return true;
}
--cfunction--