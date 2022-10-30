#the actual output and input vars
output = ""
inputs = [ ["B3", 16], [""] ]
# defining the actual big brain things
def note(note1, duration=1):
    return " M__NOTE(_" + note1 + ", " + str(duration) + "), "

def note2(note1, note2, duration = 32):
    returned = ""
    if duration <= 0:
        duration = 4
    while duration % 4 != 0:
        duration += 1
    for i in range(int(duration/2)):
        returned += note(note1) + note(note2)
    return returned
#defining the mindless yeet skeets
def bnote(note1):
    return note(note1, 128)
def wnote(note1):
    return note(note1, 64)
def hnote(note1):
    return note(note1, 32)
def qnote(note1):
    return note(note1, 16)
def enote(note1):
    return note(note1, 8)
def snote(note1):
    return note(note1, 4)
def bnote2(notea, noteb):
    return note2(notea, noteb, 128)
def wnote2(notea, noteb):
    return note2(notea, noteb, 64)
def hnote2(notea, noteb):
    return note2(notea, noteb, 32)
def qnote2(notea, noteb):
    return note2(notea, noteb, 16)
def enote2(notea, noteb):
    return note2(notea, noteb, 8)
def snote2(notea, noteb):
    return note2(notea, noteb, 4)
#finally done lol
# main function run
output += note("B5", 8)
output += note("E6", 16 + 8 + 32)
print(output)
