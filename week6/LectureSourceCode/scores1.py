# Averages three numbers using a list and a loop

from cs50 import get_int

# Get Scores
scores = []
for i in range(3):
    score = get_int("Score: ")
    scores.append(score)

# Print average
average = sum(scores) / len(scores)
print(f"Average: {average}")