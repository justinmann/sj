
console.write("Shall we play\n")

num : i32_random() % 10 + 1
isCorrect := false

while !isCorrect {
    str : console.readLine()
    guess : str.asI32()
    isCorrect = if guess < num {
                    console.write("Too Low\n")
                    false
                } else if guess > num {
                    console.write("Too high\n")
                    false
                } else {
                    true
                }
}

console.write("Correct\n")
