# Introduction #

Voici les étapes décrivant l'algorithme de calcul des mains de poker.

Note: tiré de cet article de [Nick's blog](http://www.kfu.com/~nsayer/blog/2007/07/algorithm-for-evaluating-poker-hands.html).

# Détails #

> I've never actually seen the full description in one place on the net, so I thought I'd  do a public service.

> First, if you're playing a game with extra cards, like Hold'em or 7 stud, you first use recursion thusly: Iterate through the set of cards, removing one at a time and recurse. From the recursion results, save the best hand and return it.

> Once you get down to 5 cards, you first take a histogram of the card ranks. That is, for each rank in the hand, count how often it appears. Sort the histogram by the count  backwards (high values first).

> If the histogram counts are 4 and 1, then the hand is quads.

> If the histogram counts are 3 and a 2, then the hand is a boat.

> If the histogram counts are 3, 1 and 1, then the hand is a set.

> If the histogram counts are 2, 2 and 1, then the hand is two pair.

> If the histogram has 4 ranks in it, then the hand is one pair.

> Next, check to see if the hand is a flush. You do this by iterating through the cards to see if the suit of a card is the same as its neighbor. If not, then the hand is not a flush. Don't return a result yet, just note whether or not it's a flush.

> Next, check for straights. Do this by sorting the list of cards. Then subtract the rank of the bottom card from the top card. If you get 4, it's a straight. At this point, you must also check either for the wheel or for broadway, depending on whether your sort puts the ace at the top or bottom. I would expect most folks to put the ace at the top of the sort, since it is usually a high card. So to check for the wheel, check to see if the top card is an ace and the 2nd to top card is a 5. If so, then it is the wheel.

> If the hand is a straight and a flush, it's a straight-flush. Otherwise if it's one or the other, you can return that.

> If we haven't matched the hand by now, it's High Card.

> Once you know what the hand is, it is fairly straightforward to compare two hands of the same type. For straights, you simply compare the top card. For flushes, you iterate down through a reverse sort of the ranks until you find a higher card or run out. For the histogram-based hands, you start at the beginning of the reverse-sorted count list and compare the ranks (two pair is tricky - you must always evaluate the higher of the two pairs for each hand first - the histogram won't help, then the lower pair, then the kicker).

> Checking for a low (for high/low or Razz) is a little easier. Sort the hand by rank. Iterate through the list. If any card is bigger than an 8 or is the same rank as it's neighbor, it's not a low hand.