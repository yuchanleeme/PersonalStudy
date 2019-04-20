# https://www.inflearn.com/course/python-%ED%8C%8C%EC%9D%B4%EC%8D%AC-%EC%9E%85%EB%AC%B8-%EA%B0%95%EC%A2%8C/
# LAB : Yesterday Letter Counter

f = open("yesterday.txt", 'r')
yesterday_lyric = ""
while 1:
    line = f.readline()
    if not line:
        break
    yesterday_lyric = yesterday_lyric + line.strip() + "\n"
f.close()
n_of_Yesterday = yesterday_lyric.count("Yesterday")
n_of_yesterday = yesterday_lyric.count("yesterday")
print("Number of a word 'Yesterday'", n_of_Yesterday)
print("Number of a word 'yesterday'", n_of_yesterday)
