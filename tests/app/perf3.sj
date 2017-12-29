include "lib/ui/ui.sj"

vertex_location_format : "vertex:3f"

vertex_location(
    location : vec3()
) { this }

vertex_location_getRawSize() {
    vec3_getRawSize()
}

vertex_location_rawCopy(v : 'vertex_location, p := 'ptr) {
    p = v.location.rawCopy(p)
    p
}

a_light : vec4(0.2f, 0.2f, 0.2f, 1.0f)
s_light : vec4(0.9f, 0.8f, 0.8f, 1.0f)
l_pos : vec4(-0.005f, 0.0005f, 0.0f, 0.0f)
WIDTH : 1920
HEIGHT : 1080
oncept : 0
dotsscale : 1000 // dots array scale, 100^(x), example 100 1000 10000 1000000 etc
dots : ((f32_pi * dotsscale as f32) as i32)
rotateradius : 1.0f
persp := 45.0f
stateof : [ true, true, true ]
stateofdir : [ true, true, true ]
mainrot : [ false, false ]
scale : 0.5f
img_dotsscale : 100
img_dots : (f32_pi * img_dotsscale as f32) as i32

test #element (
    funcid := 0
    lastfuncid := 0
    datax : array!f32(dots).init(0.0f)
    datay : array!f32(dots).init(0.0f)
    rotatex := 0.0f
    rotatey := 0.0f
    rotatez := 0.0f
    
    datavert1x : array!f32(img_dots).init(0.0f)
    datavert1y : array!f32(img_dots).init(0.0f)
    datavert2x : array!f32(img_dots).init(0.0f)
    datavert2y : array!f32(img_dots).init(0.0f)
    datavert3x : array!f32(img_dots).init(0.0f)
    datavert3y : array!f32(img_dots).init(0.0f)
    datavert4x : array!f32(img_dots).init(0.0f)
    datavert4y : array!f32(img_dots).init(0.0f)
    datavert5x : array!f32(img_dots).init(0.0f)
    datavert5y : array!f32(img_dots).init(0.0f)
    
    datahotizont1x : array!f32(img_dots).init(0.0f)
    datahotizont1y : array!f32(img_dots).init(0.0f)
    datahotizont2x : array!f32(img_dots).init(0.0f)
    datahotizont2y : array!f32(img_dots).init(0.0f)
    datahotizont3x : array!f32(img_dots).init(0.0f)
    datahotizont3y : array!f32(img_dots).init(0.0f)
    datahotizont4x : array!f32(img_dots).init(0.0f)
    datahotizont4y : array!f32(img_dots).init(0.0f)
    datahotizont5x : array!f32(img_dots).init(0.0f)
    datahotizont5y : array!f32(img_dots).init(0.0f)

    shader : shader("shaders/point.vert", "shaders/point.frag")
    _rect := rect()
    projection := mat4()
    view := mat4()
    
    getSize(maxSize : 'size) {
        size(maxSize.w, maxSize.h)
    }

    getRect()'rect { copy _rect }

    setRect(rect_ : 'rect)'void {
        if _rect != rect_ {
            _rect = copy rect_
            projection = copy mat4_perspective(persp * 2.0f, _rect.h as f32 / _rect.w as f32, 0.1f, 100.0f)
            view = copy mat4_lookAtLH(vec3(0.0f, 0.0f, -7.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f))
        }
        void
    }

    fireMouseEvent(mouseEvent : 'mouseEvent)'bool { true }

    render(scene : 'scene2d)'void {
        calculate()
        findaxis()

        axis : vec3(rotatex, rotatey, rotatez).normalize()
        model := mat4_identity()

        color : vec3(
            if rotatex > 0.0f { rotatex } else { (-1.0f * rotatex) / 14.0f }
            if rotatey > 0.0f { rotatey } else { (-1.0f * rotatey) / 14.0f }
            if rotatez > 0.0f { rotatez } else { (-1.0f * rotatez) / 14.0f }
        )

        if funcid == 18 {
            vertices : array!vertex_location(dots).init(vertex_location())
            index := 0
            for n : 0 to img_dots {
                /* glVertex3f(datahotizont1x[n] * scale, datahotizont1y[n] * scale, 0.0f)
                glVertex3f(datahotizont2x[n] * scale, datahotizont2y[n] * scale, 0.0f)
                glVertex3f(datahotizont3x[n] * scale, datahotizont3y[n] * scale, 0.0f)
                glVertex3f(datahotizont4x[n] * scale, datahotizont4y[n] * scale, 0.0f)
                glVertex3f(datahotizont5x[n] * scale, datahotizont5y[n] * scale, 0.0f)
                
                glVertex3f(datavert1x[n] * scale, datavert1y[n] * scale, 0.0f)
                glVertex3f(datavert2x[n] * scale, datavert2y[n] * scale, 0.0f)
                glVertex3f(datavert3x[n] * scale, datavert3y[n] * scale, 0.0f)
                glVertex3f(datavert4x[n] * scale, datavert4y[n] * scale, 0.0f)
                glVertex3f(datavert5x[n] * scale, datavert5y[n] * scale, 0.0f)
                
                glVertex3f(datahotizont1x[n] * scale + 4.35f + 1.0f / 3.0f, datahotizont1y[n] * scale + 3.8f, 0.0f)
                glVertex3f(datahotizont2x[n] * scale + 2.18f + 1.0f / 3.0f, datahotizont2y[n] * scale + 1.8f, 0.0f)
                glVertex3f(datahotizont3x[n] * scale + 2.34f + 1.0f / 3.0f, datahotizont3y[n] * scale + 0.8f, 0.0f)
                glVertex3f(datahotizont4x[n] * scale + 1.65f + 1.0f / 3.0f, datahotizont4y[n] * scale - 1.2f, 0.0f)
                glVertex3f(datahotizont5x[n] * scale + 1.35f + 1.0f / 3.0f, datahotizont5y[n] * scale - 2.2f, 0.0f)
                
                glVertex3f(datavert1x[n] * scale + 4.005f + 1.0f / 6.0f, datavert1y[n] * scale + 0.8f, 0.0f)
                glVertex3f(datavert2x[n] * scale + 4.05f - 1.0f / 6.0f, datavert2y[n] * scale + 2.8f, 0.0f)
                glVertex3f(datavert3x[n] * scale + 3.0f - 1.0f / 6.0f, datavert3y[n] * scale - 0.2f, 0.0f)
                glVertex3f(datavert4x[n] * scale + 2.0f - 1.0f / 6.0f, datavert4y[n] * scale - 0.2f, 0.0f)
                glVertex3f(datavert5x[n] * scale + 1.0f - 1.0f / 6.0f, datavert5y[n] * scale - 0.2f, 0.0f) */
            }
        } else {
            vertices : array!vertex_location(dots).init(vertex_location())
            index := 0
            for n : 0 to dots {
                vertices[index] = vertex_location(
                    vec3(datax[n] * scale, datay[n] * scale, 0.0f)
                )
                index++
            }

            v : vertexBuffer!vertex_location(
                format : copy vertex_location_format
                vertices : copy vertices
            )

            for r : 0 to 360 {
                model = copy (model * mat4_rotate(r as f32 / (100.0f / rotateradius), axis))
                glUseProgram(shader)
                glBlendFunc(glBlendFuncType.GL_ONE, glBlendFuncType.GL_ONE)
                glUniformMat4(glGetUniformLocation(shader, "viewModel"), view * model)
                glUniformMat4(glGetUniformLocation(shader, "projection"), projection)
                glUniformVec3(glGetUniformLocation(shader, "color"), color)
                v.render(glDrawMode.GL_POINTS)
            }
        }
    }

    calculate() {
        switch funcid {
            0 { 
                for n : 0 to dots {
                    t : gettm(1, n)
                    datax [n] = t
                    datay [n] = f32_tan(t)
                }
            }
            1 {
                for n : 0 to dots {
                    t : gettm(1, n)
                    datax [n] = t
                    datay [n] = t * t*t
                }
            }
            2 {
                for n : 0 to dots {
                    t : gettm(2, n)
                    datax [n] = t
                    datay [n] = (6.0f * f32_sin(t)) / 2.0f
                    
                }
            }
            3 {
                for n : 0 to dots {
                    t : gettm(1, n)
                    datax [n] = t
                    datay [n] = 1.0f / f32_tan(t)
                }
            }
            4 {
                for n : 0 to dots {
                    t : gettm(2, n)
                    datax [n] = t
                    datay [n] = f32_abs(t) * f32_sin(t)                    
                }
            }
            5 {
                for n : 0 to dots {
                    t : gettm(2, n)
                    datax [n] = t
                    datay [n] = t / (t * t)
                }
            }
            6 {
                for n : 0 to dots {
                    t : gettm(2, n)
                    datax [n] = t
                    datay [n] = t * f32_sin(t)
                }
            }
            7 {
                for n : 0 to dots {
                    t : gett(2, n)
                    datax [n] = 2.0f * f32_cos(t) + f32_cos(2.0f * t)
                    datay [n] = 2.0f * f32_sin(t) - f32_sin(2.0f * t)
                }
            }
            8 {
                for n : 0 to dots {
                    t : gett(2, n)
                    datax [n] = 4.0f * (f32_cos(t) + f32_cos(5.0f * t) / 5.0f)
                    
                    datay [n] = 4.0f * (f32_sin(t) - f32_sin(5.0f * t) / 5.0f)
                    
                }
            }
            9 {
                for n : 0 to dots {
                    t : gett(20, n)
                    datax [n] = 2.8f * (f32_cos(t) + f32_cos(1.1f * t) / 1.1f)                    
                    datay [n] = 2.8f * (f32_sin(t) - f32_sin(1.1f * t) / 1.1f)
                }
            }
            10 {
                for n : 0 to dots {
                    t : gett(2, n)
                    datax [n] = 3.0f * (1.0f + f32_cos(t)) * f32_cos(t)                    
                    datay [n] = 3.0f * (1.0f + f32_cos(t)) * f32_sin(t)                    
                }
            }
            11 {
                for n : 0 to dots {
                    t : gett(2, n)
                    datax [n] = 3.0f * f32_sin(t + f32_pi / 2.0f)                    
                    datay [n] = 3.0f * f32_sin(2.0f * t)
                }
            }
                //Butterfly
            12 {
                for n : 0 to dots {
                    t : gett(12, n)
                    datax [n] = f32_sin(t)*(f32_exp(f32_cos(t)) - 2.0f * f32_cos(4.0f * t) + f32_pow(f32_sin(t / 12.0f), 5.0f))                    
                    datay [n] = f32_cos(t)*(f32_exp(f32_cos(t)) - 2.0f * f32_cos(4.0f * t) + f32_pow(f32_sin(t / 12.0f), 5.0f))                    
                }
            }
            //heart <3
            13 {
                for n : 0 to dots {
                    t : gett(2, n)
                    datax [n] = (16.0f * f32_pow(f32_sin(t), 3.0f)) / 4.0f
                    datay [n] = (13.0f * f32_cos(t) - 5.0f * f32_cos(2.0f * t) - 2.0f * f32_cos(3.0f * t) - f32_cos(4.0f * t)) / 4.0f                    
                }
            }
            14 {
                for n : 0 to dots {
                    t : gettm(1, n)
                    datax [n] = 5.0f * f32_sin(t)
                    datay [n] = 5.0f * f32_cos(t)
                }
            }
            15 {
                for n : 0 to dots {
                    t : gettm(1, n)
                    datax [n] = (f32_cos(t) + f32_pow(f32_cos(80.0f * t), 3.0f))*3.0f
                    datay [n] = (f32_sin(80.0f * t) + f32_pow(f32_sin(t), 4.0f))*2.5f
                }
            }
            16 {
                for n : 0 to dots {
                    t : gettm(1, n)
                    datax [n] = f32_cos(t) * f32_sqrt((2.0f * 2.0f * f32_pow(f32_sin(t), 2.0f) - 5.0f * 5.0f * f32_pow(f32_cos(t), 2.0f)) / (f32_pow(f32_sin(t), 2.0f) - f32_pow(f32_cos(t), 2.0f)))
                    datay [n] = f32_sin(t) * f32_sqrt((2.0f * 2.0f * f32_pow(f32_sin(t), 2.0f) - 5.0f * 5.0f * f32_pow(f32_cos(t), 2.0f)) / (f32_pow(f32_sin(t), 2.0f) - f32_pow(f32_cos(t), 2.0f)))
                }
            }
            17 {
                for n : 0 to dots {
                    t : gettm(1, n)
                    datax [n] = 3.0f * f32_cos(t)*(1.0f - 2.0f * f32_pow(f32_sin(t), 2.0f))
                    datay [n] = 3.0f * f32_sin(t)*(1.0f - 2.0f * f32_pow(f32_cos(t), 2.0f))
                }
            }
            //18 p and d cahrs
            default {
                funcid = 18
                persp = 50.0f
                imgdata_FunctionList()
            }
        }
    }

    findaxis() {
        if !mainrot[0] {
            if stateof[0] && stateof[1] && stateof[2] {               
                if (stateofdir[0]) {
                    rotatey += 0.05f
                    stateofdir[0] = rotatey < 7.0f
                } else {
                    stateof[0] = stateofdir[0]
                }
            } else if stateof[1] && (!stateof[0]) && stateof[2] {
                if rotatey > 0.0f { rotatey -= 0.05f }
                if stateofdir[1] {
                    rotatex += 0.05f
                    stateofdir[1] = rotatex < 7.0f
                } else {
                    stateof[1] = stateofdir[1]
                }
            }
            if (!stateof[1]) && (!stateof[0]) && stateof[2] {
                if rotatex > 0.0f { rotatex -= 0.05f }
                if stateofdir[2] {
                    rotatez += 0.05f
                    stateofdir[2] = rotatez < 7.0f
                } else {
                    stateof[2] = stateofdir[2]
                    mainrot[0] = !stateofdir[2]
                }
            }
        } else {
            if !mainrot[1] {
                if stateofdir[0] {
                    rotatey += 0.05f
                    stateofdir[0] = rotatey < 7.0f
                    
                    if (stateofdir[2]) {
                        rotatez += 0.05f
                        stateofdir[2] = rotatez < 7.0f
                    } else {
                        rotatez -= 0.05f
                        stateofdir[2] = rotatez < -7.0f
                    }
                } else {
                    if (stateofdir[1]) {
                        rotatex += 0.05f
                        stateofdir[1] = rotatex < 7.0f
                        if (stateofdir[2]) {
                            rotatez += 0.05f
                            stateofdir[2] = rotatez < 7.0f
                        } else {
                            rotatez -= 0.05f
                            stateofdir[2] = rotatez < -7.0f
                        }
                    } else {
                        rotatex -= 0.05f
                        stateofdir[1] = rotatex < -7.0f
                        if (stateofdir[2]) {
                            rotatez += 0.05f
                            stateofdir[2] = rotatez < 7.0f
                            if funcid != 18 { mainrot[1] = !stateofdir[2] }  //end this and turn next
                        } else {
                            rotatez -= 0.05f
                            stateofdir[2] = rotatez < -7.0f
                        }
                    }
                    rotatey -= 0.05f
                    stateofdir[0] = rotatey < -7.0f
                }
            }
        }
        if mainrot[0] && mainrot[1] {
            if (rotatez > 0.0f) {
                rotatez -= 0.1f
                void
            } else {
                rotatez = 0.0f
                rotatex = 0.0f
                rotatey = 0.0f
                stateof[0] = true
                stateof[1] = true
                stateof[2] = true
                stateofdir[0] = true
                stateofdir[1] = true
                stateofdir[2] = true
                mainrot[0] = false
                mainrot[1] = false
                funcid += 1
                void
            }
        }    
    }

    //t=[0, pi*xpi]
    gett(xpi : 'i32, n : 'i32) {
        xpi as f32 * (n as f32 / dotsscale as f32)
    }

    //t=[-pi*xpi, pi*xpi]
    gettm(xpi : 'i32, n : 'i32) {
        xpi as f32 * (-1.0f * f32_pi) + xpi as f32 * 2.0f * (n as f32 / dotsscale as f32)
    }

    //t=[-pi*xpi, pi*xpi]
    img_gettm(xpi : 'i32, n : 'i32) {
        xpi as f32 * (-1.0f * f32_pi) + xpi as f32 * 2.0f * (n as f32 / img_dotsscale as f32)
    }

    imgdata_FunctionList() {
        for n : 0 to img_dots {
            t : img_gettm(1, n)
            datavert1x [n] = -3.0f + (t * 0.98f) / 3.0f
            datavert1y [n] = t * 0.98f
            datavert2x [n] = -2.0f - 2.0f / 3.0f + (t / f32_pi) / 3.0f
            datavert2y [n] = (t / f32_pi) - 2.0f
            datavert3x [n] = -1.0f - 2.0f / 3.0f + (t / f32_pi) / 3.0f
            datavert3y [n] = (t / f32_pi) + 1.0f
            datavert4x [n] = -2.0f / 3.0f + (t / f32_pi) / 3.0f
            datavert4y [n] = 1.0f + (t / f32_pi)
            datavert5x [n] = 1.0f / 3.0f + ((t / f32_pi)*2.0f) / 3.0f
            datavert5y [n] = 1.0f + (t / f32_pi)*2.0f
            
            
            datahotizont1x [n] = -3.5f + t / 7.0f
            datahotizont1y [n] = -3.0f
            datahotizont2x [n] = -1.0f - 1.0f / 3.0f + (t / f32_pi)
            datahotizont2y [n] = -1.0f
            datahotizont3x [n] = -1.5f + (t / f32_pi) / 2.0f
            datahotizont3y [n] = 0.0f
            datahotizont4x [n] = -0.8f + (t / f32_pi) / 2.0f
            datahotizont4y [n] = 2.0f
            datahotizont5x [n] = -1.0f / 2.0f + (t / f32_pi)*(2.0f - 1.0f / 2.0f)
            datahotizont5y [n] = 3.0f            
        }
    }
) { this } 

root : test() as #element

mainLoop_showFPS = true
windowRender_disableVSync()
rootWindowRenderer.setSize(size(1920, 1080))

runLoop()