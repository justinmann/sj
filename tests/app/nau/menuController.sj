menuController(
    start() {
        menuScene.animateLookAt(vec3(0.0f, 0.0f, 50.0f), 5000)
    }

    viewFieldMenu() {
        m : modelsById["fieldMenu"]
        ifValid m {
            c : m.getCenter()
            w : m.getWorld()
            l : w * c.asVec4()
            d : l.asVec3()

            crossFade : heap crossFadeElement(
                fromElement : menuElement
                toElement : fieldElement
            )

            root = heap crossFade as #element

            menuScene.animateLookAt(d, 2000)
            menuScene.animateCameraDistance(3.0f, 2000)

            animator.animations.add(
                heap animation!f32(
                    startValue : 0.0f
                    endValue : 1.0f
                    start : animator.current + 1500
                    end : animator.current + 3000
                    setValue : crossFade.setAmount
                ) as #animation
            )
        }
        void
    }

    onBackFromField() {
        crossFade : heap crossFadeElement(
            fromElement : fieldElement
            toElement : menuElement
        )

        root = heap crossFade as #element

        menuScene.animateLookAt(vec3(0.0f, 0.0f, 50.0f), 4000)
        menuScene.animateCameraDistance(5.0f, 4000)

        animator.animations.add(
            heap animation!f32(
                startValue : 0.0f
                endValue : 1.0f
                start : animator.current + 500
                end : animator.current + 3000
                setValue : crossFade.setAmount
            ) as #animation
        )

        void
    }
) { this }

menuController : heap menuController()