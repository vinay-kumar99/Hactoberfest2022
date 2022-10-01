class Solution:
    def pushDominoes(self, string: str) -> str:
        low, high = 0, len(string) - 1
        string = list(string)

        if string[low] == ".":
            for i in range(len(string)):
                if string[i] == "R": 
                    low = i
                    break

                if string[i] == "L":
                    for j in range(i):
                        string[j] = "L"
                    break

        if string[high] == ".":
            for i in range(len(string)-1,-1,-1):
                if string[i] == "L": 
                    high = i
                    break

                if string[i] == "R":
                    for j in range(i, len(string)):
                        string[j] = "R"
                    break

        i = low
        for j in range(low+1, high+1):
            if string[i] == "R" and string[j] == "L":
                mid = (i+j) //2 
                temp = j
                while i != j:
                    if i >= temp:
                        i = j
                        break

                    string[i] = "R"
                    string[temp] = "L"

                    temp-=1
                    i+=1

            if string[i] == "R" and string[j] == "R":
                while i != j:
                    string[i] = "R"
                    i+=1

            if string[i] == "L" and string[j] == "L":
                while i != j:
                    string[i] = "L"
                    i+=1

            if string[i] == "L" and string[j] == "R":
                i = j

        return "".join(string)
