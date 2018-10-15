import sys

max_student_count = int(sys.stdin.readline())

scores = []
for line in sys.stdin:
    subject_scores = list(map(int, line.strip().split()[-3:]))
    if any(x < 40 for x in subject_scores):
        continue
    scores.append(sum(subject_scores))

if len(scores) <= max_student_count:
    print(0)
else:
    scores = sorted(scores, reverse=True)
    max_insufficient_score = scores[max_student_count]
    if scores[0] == max_insufficient_score:
        print(1)
    else:
        for i in range(max_student_count, -1, -1):
            if scores[i] > max_insufficient_score:
                break
        print(scores[i])
