import re
pattern = r'\.[a-zA-Z]+$'
domains=[]
TLD=[]
with open('domain.txt', 'r') as file:
    for line in file:
        domain = line.strip()
        domains.append(domain)
print(domains)
for dom in domains:
    match = re.search(pattern, dom)
    if match:
        TLD.append(match.group(0))
print(TLD)
