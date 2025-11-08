invite = ['Corvo', 'Emily', 'Ren', 'Yu', 'Makoto']

def invitations(invite):
    for i in invite:
        print("Dear ", i, ", you are invited to dinner.", sep = "")
        i =+ 1

invitations(invite)

print('')
print("Sorry, Emily can't come to dinner.")

invite.remove('Emily')
invite.insert(1, 'Wyman')

invitations(invite)

print('')
print('Hey, I can get more people!')
invite.insert(0, 'Izanagi')
invite.insert(3, 'Arsené')
invite.append('Orpheus')

print('')
invitations(invite)

print('')
print('I can only invite 2 people :(')

while len(invite) > 2:
    cancel = invite.pop()
    print("Sorry, ", cancel, ", I can't invite you.", sep = "")

print('')
invitations(invite)

while len(invite) > 0:
    del invite[-1]
print('')
print(invite)
