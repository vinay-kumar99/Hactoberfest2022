#character count game
import pprint
message='An apple a day keeps a doctor away'
count={}

for character in message.upper():
    count.setdefault(character,0)
    count[character]=count[character]+1
    
print(count)
#or
#pprint.pprint(count)#pprint stands for 'pretty print'
#or
#text=pprint.pformat(count)
#print(text)
