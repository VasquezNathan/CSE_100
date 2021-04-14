import discord
import os
client = discord.Client()
n_words = ["NIGGA", "NIGGER", "NEGRO", "N WORD"]
@client.event
async def on_ready():
    print('We have logge din as {0.user}'.format(client))
@client.event
async def on_message(message):
    if message.author == client.user:
        return
    file = open('count.txt', 'r')
    x = int(file.readline())
    for word in message.content.split():
        if word.upper() in n_words:
            x += 1
            print(x)
    file.close()
    file = open('count.txt', 'w')
    file.write(str(x))
    if '!nigga' in message.content:
        await message.channel.send('the n word has been said: ' + str(x) + ' times')

client.run('ODMxNjc2MTEwNjQyMjE2OTYy.YHYsvA.UDDmnQWwAiz0vY15N6anQN971J0')