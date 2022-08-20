import re;

ReqID_List = []
ImplementedReqs = []
NonImplementedReqs = []

def read():
    with open('project-requirements-template.csv') as file:
        lines = file.readlines()
        lines = [line.strip() for line in lines] # jede zeile trennen
        for line in lines:
            result = re.findall("F+[0-9]", line)
            if result != []:
                column = line.split(";")
                ReqID_List.append(column[1]) # Liste mit ReqIDs wird aus Excel file ausgelesen




def parse_log():
    i = 0
    with open('log.txt') as file:
        lines = file.readlines()
        lines = [line.strip() for line in lines]
        for line in lines:
            while i < len(ReqID_List):
                if line.__contains__(ReqID_List[i]):
                    if not ImplementedReqs.__contains__(ReqID_List[i]):
                        ImplementedReqs.append(ReqID_List[i])
                i += 1
            i = 0
        print(ImplementedReqs)
        NotImplemented = [item for item in ReqID_List if item not in ImplementedReqs]
        i = 0
        while i < len(NotImplemented):
            NonImplementedReqs.append(NotImplemented[i])
            i += 1
        print(NonImplementedReqs)

def generate_report():
    file = open('output/output.txt', 'a')
    file.write('Requirements' + '\n' +
               '##############################################################################' + '\n')
    file.write('Tested Requirements: ' + '\n')
    i = 0
    while i < len(ImplementedReqs):
        file.write(ImplementedReqs[i] + '\n')
        i += 1
    file.write('Not Tested Requirements: ' + '\n')
    y = 0
    while y < len(NonImplementedReqs):
        file.write(NonImplementedReqs[y] + '\n')
        y += 1
    i = len(ImplementedReqs)/(len(ReqID_List))
    file.write('ReqCoverage: ' + str(i))

if __name__ == '__main__':
    read()
    parse_log()
    generate_report()

