import re
text = 'alpha beta...gamma delta'
pat = '[a-zA-Z]+'
print(re.findall(pat, text))
print(re.match('done|quit', 'doneing'))
print(re.match('done|quit', 'it is done'))
print(re.match('to', 'To be,\nor not to be'))
print(re.search('to', 'To be,\nor not to be'))
print(re.split('[\. ]+', text))
print(re.split('[\. ]+', text, 2))
print(re.split('[\. ]+', text, 1))
