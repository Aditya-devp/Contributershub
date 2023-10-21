import tkinter as tk
import random

def mine_gold():
    global gold, pickaxe_durability
    if pickaxe_durability > 0:
        mined_gold = random.randint(5, 20)
        gold += mined_gold
        pickaxe_durability -= 1
        update_display()
        log_text.set(f"You mined {mined_gold} gold.")
    else:
        log_text.set("Your pickaxe is broken. You need to buy a new one.")

def buy_pickaxe():
    global gold, pickaxe_durability
    cost = random.randint(10, 30)
    if gold >= cost:
        gold -= cost
        pickaxe_durability = 5
        update_display()
        log_text.set(f"You bought a new pickaxe for {cost} gold.")
    else:
        log_text.set("You can't afford a new pickaxe.")

def update_display():
    gold_label.config(text=f"Gold: {gold}")
    pickaxe_label.config(text=f"Pickaxe Durability: {pickaxe_durability}")

gold = 100
pickaxe_durability = 5

app = tk.Tk()
app.title("Miner's Game")

gold_label = tk.Label(app, text=f"Gold: {gold}")
gold_label.pack()

pickaxe_label = tk.Label(app, text=f"Pickaxe Durability: {pickaxe_durability}")
pickaxe_label.pack()

mine_button = tk.Button(app, text="Mine Gold", command=mine_gold)
mine_button.pack()

buy_button = tk.Button(app, text="Buy Pickaxe", command=buy_pickaxe)
buy_button.pack()

log_text = tk.StringVar()
log_label = tk.Label(app, textvariable=log_text)
log_label.pack()

update_display()

app.mainloop()
