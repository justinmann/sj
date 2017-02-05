include "common.sj"

num : random.nextInt() % 10 + 1
isCorrect = false
guessCount = 0

while !isCorrect {
    guessCount ++
    str : console.readLine()
    guess : parse.toInt(str)
    if guess < num {
        console.write("Too Low\n")
    } else if guess > num {
        console.write("Too high\n")
    } else {
        isCorrect = true
    }
}

console.write("Correct\n")
