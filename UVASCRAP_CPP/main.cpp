#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>

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

/*
//2 2 4 5 5
//4 5 5 6 6
//2 2 4 4 5
Notice how the 3rd card (h[3]) always has the highest value
*/
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

/*
//2 2 4 5 5
//4 5 5 6 6
//2 2 4 4 5
*/
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
    } else if (tempScore == 7) { /* Full house  */
        /* Not possible */
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
    }
}

void clearHand(vector<Card*> &v) {
    for (vector<Card*>::iterator it = v.begin(); it != v.end(); it++) {
        delete *it;
    }
}

void showHand(vector<Card*> &v) {
    for (vector<Card*>::iterator it = v.begin(); it != v.end(); it++) {
        cout << (*it)->value << "" << (*it)->suit << endl;
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

int scoreHand(vector<Card*> &h, string color) {
    int temp, s = 0;
    if ((temp = isStraightFlush(h))) {
        s = 900 + temp;
        cout << color << " straight flush - " << s << endl;
    } else if ((temp = isFourOfAKind(h))) {
        s = 800 + temp;
        cout << color << " 4 of a kind - " << s << endl;
    } else if ((temp = isFullHouse(h))) {
        s = 700 + temp;
        cout << color << " full house - " << s << endl;
    } else if ((temp = isFlush(h))) {
        s = 600 + temp;
        cout << color << " flush - " << s << endl;
    } else if ((temp = isStraight(h))) {
        s = 500 + temp;
        cout << color << " straight - " << s << endl;
    } else if ((temp = isThreeOfAKind(h))) {
        s = 400 + temp;
        cout << color << " three of a kind - " << s << endl;
    } else if ((temp = isTwoPairs(h))) {
        s = 300 + temp;
        cout << color << " two pair - " << s << endl;
    } else if ((temp = isPair(h))) {
        s = 200 + temp;
        cout << color << " pair - " << s << endl;
    }
    if (temp > 0) showHand(h);
    return s;
}

int main() {
    ifstream read("test.txt");
    string line;
    vector<Card*> b;
    vector<Card*> w;
    string cardStr;
    int i;
    int N = 1;
    int scoreBlack, scoreWhite;
    string BLACK = "black";
    string WHITE = "white";
    while (getline(read, line)) {
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
        cout << "Hand " << N++ << endl;

        scoreBlack = scoreHand(b, BLACK);
        scoreWhite = scoreHand(w, WHITE);


    }
    read.close();
    return 0;
}
