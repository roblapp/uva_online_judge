#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

/*
Accepted: 0.000s
Description: ad-hoc
*/

#define read cin

using namespace std;

class Card {
public:
    char suit;
    int value;
    Card(char s, int v): suit(s), value(v) {};
};

int isStraightFlush(vector<Card*> &h) {
    int i, N = h.size();
    char suit = h[0]->suit;
    for (i = 1; i < N; i++) {
        if (suit != h[i]->suit) return 0;
    }
    if (h[0]->value + 1 == h[1]->value &&
        h[1]->value + 1 == h[2]->value &&
        h[2]->value + 1 == h[3]->value &&
        h[3]->value + 1 == h[4]->value) {
            return h[4]->value;
    }
    return 0;
}

int isFourOfAKind(vector<Card*> &h) {
    if (h[0]->value == h[1]->value && h[1]->value == h[2]->value && h[2]->value == h[3]->value) {
        return h[0]->value;
    }
    if (h[1]->value == h[2]->value && h[2]->value == h[3]->value && h[3]->value == h[4]->value) {
        return h[1]->value;
    }
    return 0;
}

int isFullHouse(vector<Card*> &h) {
    if (h[0]->value == h[1]->value && h[1]->value == h[2]->value) {
        if (h[3]->value == h[4]->value) {
            return (h[0]->value);
        }
    } else if (h[2]->value == h[3]->value && h[3]->value == h[4]->value) {
        if (h[0]->value == h[1]->value) {
            return (h[2]->value);
        }
    }
    return 0;
}

int isFlush(vector<Card*> &h) {
    if (h[0]->suit == h[1]->suit &&
        h[1]->suit == h[2]->suit &&
        h[2]->suit == h[3]->suit &&
        h[3]->suit == h[4]->suit) {
            return h[4]->value;
        }
    return 0;
}

int isStraight(vector<Card*> &h) {
    if (h[0]->value + 1 == h[1]->value &&
        h[1]->value + 1 == h[2]->value &&
        h[2]->value + 1 == h[3]->value &&
        h[3]->value + 1 == h[4]->value) {
            return h[4]->value;
    }
    return 0;
}

int isThreeOfAKind(vector<Card*> &h) {
    if (h[0]->value == h[1]->value && h[1]->value == h[2]->value) {
        return h[0]->value;
    } else if (h[1]->value == h[2]->value && h[2]->value == h[3]->value) {
        return h[1]->value;
    } else if (h[2]->value == h[3]->value && h[3]->value == h[4]->value) {
        return h[2]->value;
    }
    return 0;
}

int isTwoPairs(vector<Card*> &h) {
    if (h[0]->value == h[1]->value) {
        if (h[2]->value == h[3]->value || h[3]->value == h[4]->value) {
            return h[3]->value;
        }
    } else if (h[1]->value == h[2]->value) {
        if (h[3]->value == h[4]->value) {
            return h[3]->value;
        }
    }
    return 0;
}

int isPair(vector<Card*> &h) {
    if (h[0]->value == h[1]->value) {
        return h[0]->value;
    } else if (h[1]->value == h[2]->value) {
        return h[1]->value;
    } else if (h[2]->value == h[3]->value) {
        return h[2]->value;
    } else if (h[3]->value == h[4]->value) {
        return h[3]->value;
    }
    return 0;
}

void scoreByHighCardRule(vector<Card*> &b, vector<Card*> &w, bool &isTie, bool &isBlackWinner) {
    int i;
    for (i = 4; i >= 0 && b[i]->value == w[i]->value; i--) ;
    if (i < 0) {
        isTie = true;
        isBlackWinner = false;
    } else if (b[i]->value > w[i]->value) {
        isTie = false;
        isBlackWinner = true;
    } else {
        isTie = false;
        isBlackWinner = false;
    }
}

void scoreTwoPairTie(vector<Card*> &h, int &lowPair, int &single) {
    if (h[0]->value == h[1]->value) {
        lowPair = h[0]->value;
        single = (h[3]->value == h[4]->value) ? h[2]->value : h[4]->value;
    } else {
        single = h[0]->value;
        lowPair = h[1]->value;
    }
}

void scorePairTie(vector<Card*> &h, vector<int> &solution) {
    solution.clear();
    if (h[0]->value == h[1]->value) {
        solution.push_back(h[4]->value);
        solution.push_back(h[3]->value);
        solution.push_back(h[2]->value);
    } else if (h[1]->value == h[2]->value) {
        solution.push_back(h[4]->value);
        solution.push_back(h[3]->value);
        solution.push_back(h[0]->value);
    } else if (h[2]->value == h[3]->value) {
        solution.push_back(h[4]->value);
        solution.push_back(h[1]->value);
        solution.push_back(h[0]->value);
    } else {
        solution.push_back(h[2]->value);
        solution.push_back(h[1]->value);
        solution.push_back(h[0]->value);
    }
}

void breakTie(vector<Card*> &b, vector<Card*> &w, int score, bool &isBlackWinner, bool &isTie) {
    int tempScore = score / 100; /* Scores are equal here... */
    if (tempScore == 9) { /* Straight flush */
        isTie = true;
        isBlackWinner = false;
    } else if (tempScore == 8) { /* Four of a kind */
        /* Not possible */
        isTie = true;
        isBlackWinner = false;
    } else if (tempScore == 7) { /* Full house  */
        /* Not possible */
        isTie = true;
        isBlackWinner = false;
    } else if (tempScore == 6) { /* Flush */
        scoreByHighCardRule(b, w, isTie, isBlackWinner);
    } else if (tempScore == 5) { /* Straight */
        /* Let this remain a tie */
        isTie = true;
        isBlackWinner = false;
    } else if (tempScore == 4) { /* Three of a kind */
        /* Let this remain a tie */
        isTie = true;
        isBlackWinner = false;
    } else if (tempScore == 3) { /* Two pair */
        int blackLowPair, blackSingle, whiteLowPair, whiteSingle;
        scoreTwoPairTie(b, blackLowPair, blackSingle);
        scoreTwoPairTie(w, whiteLowPair, whiteSingle);
        if (blackLowPair > whiteLowPair) {
            isTie = false;
            isBlackWinner = true;
        } else if (blackLowPair < whiteLowPair) {
            isTie = false;
            isBlackWinner = false;
        } else {
            if(blackSingle > whiteSingle) {
                isTie = false;
                isBlackWinner = true;
            } else if (blackSingle < whiteSingle) {
                isTie = false;
                isBlackWinner = false;
            } else {
                isTie = true;
                isBlackWinner = false;
            }
        }
    } else if (tempScore == 2) { /* Pair */
        vector<int> blackScore, whiteScore;
        scorePairTie(b, blackScore);
        scorePairTie(w, whiteScore);
        int i;
        for (i = 0; i < 3 && blackScore[i] == whiteScore[i]; i++) ;
        if (i == 3) { /* Same hand */
            isTie = true;
            isBlackWinner = false;
        } else if (blackScore[i] > whiteScore[i]) { /* */
            isTie = false;
            isBlackWinner = true;
        } else {
            isTie = false;
            isBlackWinner = false;
        }
    } else {
        int i;
        for (i = 4; i >= 0 && b[i]->value == w[i]->value; i--) ;
        if (i < 0) { /* Same hand */
            isTie = true;
            isBlackWinner = false;
        } else if (b[i]->value > w[i]->value) {
            isTie = false;
            isBlackWinner = true;
        } else {
            isTie = false;
            isBlackWinner = false;
        }
    }
}

void clearHand(vector<Card*> &v) {
    for (vector<Card*>::iterator it = v.begin(); it != v.end(); it++) {
        delete *it;
    }
}

bool compare (Card *c, Card *d) {
    return (c->value < d->value);
}

int getRank(char c) {
    if (isdigit(c)) return (c - '0');
    else if (c == 'T') return 10;
    else if (c == 'J') return 11;
    else if (c == 'Q') return 12;
    else if (c == 'K') return 13;
    else return 14;
}

int scoreHand(vector<Card*> &h) {
    int temp, s = 0;
    if ((temp = isStraightFlush(h))) {
        s = 900 + temp;
    } else if ((temp = isFourOfAKind(h))) {
        s = 800 + temp;
    } else if ((temp = isFullHouse(h))) {
        s = 700 + temp;
    } else if ((temp = isFlush(h))) {
        s = 600 + temp;
    } else if ((temp = isStraight(h))) {
        s = 500 + temp;
    } else if ((temp = isThreeOfAKind(h))) {
        s = 400 + temp;
    } else if ((temp = isTwoPairs(h))) {
        s = 300 + temp;
    } else if ((temp = isPair(h))) {
        s = 200 + temp;
    }
    return s;
}

void processScores(vector<Card*> &b, vector<Card*> &w) {
    int scoreBlack = scoreHand(b);
    int scoreWhite = scoreHand(w);
    if (scoreBlack > scoreWhite) {
        cout << "Black wins." << endl;
    } else if (scoreBlack < scoreWhite) {
        cout << "White wins." << endl;
    } else {
        bool isBlackWinner = false, isTie = false;
        breakTie(b, w, scoreBlack, isBlackWinner, isTie);
        if (isBlackWinner) {
            cout << "Black wins." << endl;
        } else if (!isTie) {
            cout << "White wins." << endl;
        } else {
            cout << "Tie." << endl;
        }
    }
}

int main() {
    string line;
    vector<Card*> b, w;
    string cardStr;
    int i;
    while (getline(read, line) && !line.empty()) {
        b.clear(); w.clear();
        stringstream ss(line);
        for (i = 0; i < 5; i++) {
            ss >> cardStr;
            b.push_back(new Card(cardStr[1], getRank(cardStr[0])));
        }
        for (i = 0; i < 5; i++) {
            ss >> cardStr;
            w.push_back(new Card(cardStr[1], getRank(cardStr[0])));
        }
        sort(b.begin(), b.end(), compare);
        sort(w.begin(), w.end(), compare);
        processScores(b, w);
        clearHand(b);
        clearHand(w);
    }
    return 0;
}
