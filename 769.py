def main():
    buf = input()
    buflist = buf.split()
    N = int(buflist[0])
    M = int(buflist[1])
    cardlog = []
    for i in range(M):
        buf = input()
        cardlog.append(buf)
    card_count = []
    for i in range(N):
        card_count.append(0)
    current_turn = 0
    reverse = False
    lastlog = ''
    draw_stack = 0
    for log in cardlog:
        if draw_stack > 0 and lastlog != log:
            card_count[current_turn] -= draw_stack
            draw_stack = 0
            current_turn = next_turn(current_turn, reverse, N)
        card_count[current_turn] += 1
        if log == 'number':
            pass
        elif log == 'drawtwo':
            draw_stack += 2
        elif log == 'drawfour':
            draw_stack += 4
        elif log == 'skip':
            current_turn = next_turn(current_turn, reverse, N)
        elif log == 'reverse':
            reverse = not reverse
        lastlog = log
        current_turn = next_turn(current_turn, reverse, N)
    winner = next_turn(current_turn, not reverse, N)
    if lastlog == 'skip':
        winner = next_turn(winner, not reverse, N)
    print(winner + 1, card_count[winner])

def next_turn(current_turn, reverse, N):
    if reverse:
        return (current_turn - 1) % N
    else:
        return (current_turn + 1) % N

if __name__ == '__main__':
    main()
