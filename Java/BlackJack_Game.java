import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class BlackJack_Game {
    private static final int BLACKJACK = 21;
    private static final int DEALER_THRESHOLD = 17;

    private List<Card> deck;
    private List<Card> playerHand;
    private List<Card> dealerHand;

    public BlackJack_Game() {
        deck = new ArrayList<>();
        for (Suit suit : Suit.values()) {
            for (Rank rank : Rank.values()) {
                deck.add(new Card(rank, suit));
            }
        }
        Collections.shuffle(deck);
        playerHand = new ArrayList<>();
        dealerHand = new ArrayList<>();
    }

    public void play() {
        System.out.println("Welcome to BlackJack!");
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Press 'h' to hit or 's' to stand.");
            System.out.println("Your hand: " + playerHand);
            System.out.println("Dealer's hand: " + dealerHand.get(0));
            String input = scanner.nextLine();
            if (input.equals("h")) {
                playerHand.add(deck.remove(0));
                if (getHandValue(playerHand) > BLACKJACK) {
                    System.out.println("Bust! You lose.");
                    return;
                }
            } else if (input.equals("s")) {
                break;
            }
        }
        while (getHandValue(dealerHand) < DEALER_THRESHOLD) {
            dealerHand.add(deck.remove(0));
        }
        System.out.println("Your hand: " + playerHand);
        System.out.println("Dealer's hand: " + dealerHand);
        int playerValue = getHandValue(playerHand);
        int dealerValue = getHandValue(dealerHand);
        if (dealerValue > BLACKJACK || playerValue > dealerValue) {
            System.out.println("You win!");
        } else if (playerValue == dealerValue) {
            System.out.println("Push!");
        } else {
            System.out.println("You lose.");
        }
    }

    private int getHandValue(List<Card> hand) {
        int value = 0;
        int numAces = 0;
        for (Card card : hand) {
            if (card.getRank() == Rank.ACE) {
                numAces++;
            }
            value += card.getValue();
        }
        while (value > BLACKJACK && numAces > 0) {
            value -= 10;
            numAces--;
        }
        return value;
    }

    public static void main(String[] args) {
        BlackJack_Game game = new BlackJack_Game();
        game.playerHand.add(game.deck.remove(0));
        game.dealerHand.add(game.deck.remove(0));
        game.playerHand.add(game.deck.remove(0));
        game.dealerHand.add(game.deck.remove(0));
        game.play();
    }
}

enum Suit {
    CLUBS, DIAMONDS, HEARTS, SPADES
}

enum Rank {
    TWO(2), THREE(3), FOUR(4), FIVE(5), SIX(6), SEVEN(7), EIGHT(8), NINE(9), TEN(10), JACK(10), QUEEN(10), KING(10), ACE(11);

    private int value;

    Rank(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}

class Card {
    private Rank rank;
    private Suit suit;

    public Card(Rank rank, Suit suit) {
        this.rank = rank;
        this.suit = suit;
    }

    public Rank getRank() {
        return rank;
    }

    public Suit getSuit() {
        return suit;
    }

    public int getValue() {
        return rank.getValue();
    }

    @Override
    public String toString() {
        return rank + " of " + suit;
    }
}