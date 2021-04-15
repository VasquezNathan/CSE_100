import discord
import os
from gtts import *
from asyncio import sleep
client = discord.Client()
n_words = ["Words", "to", "look", "for"]

@client.event
async def on_ready():
    print('We have logged in as {0.user}'.format(client))
@client.event
async def on_message(message):
    # ignore messages that are sent by the bot
    if message.author == client.user:
        return
    file = open('count.txt', 'r')
    x = int(file.readline())
    
    for word in message.content.split():
        if word.upper() in n_words:
            # set voice_channel to None
            voice_channel=None
            # check for voice and channel, if there is one then assign voice_channel the value
            if message.author.voice and message.author.voice.channel:
                voice_channel = message.author.voice.channel
            #if voic_channel is not none then execute file playing code
            if voice_channel != None:
                channel=voice_channel.name
                print(str(message.author) + ' ' + str(channel))

                # tbh Idk what this does
                guild = message.guild
                voice = discord.utils.get(client.voice_clients, guild=guild)
                # if it is already connected to a channel then just move it, else connect
                if voice and voice.is_connected():
                    await voice.move_to(voice_channel)
                else:
                    voice = await voice_channel.connect()
                # generate mp3 file
                tts = gTTS(str(message.content), lang="en")
                tts.save("sound.mp3")
                audio_source = discord.FFmpegPCMAudio('sound.mp3')
                # if the voice is playing then do nothing, if voice is not playing then play the file and while fiel is playing then wiat for dc
                if not voice.is_playing():
                    # voice.source = discord.PCMVolumeTransformer(voice.source, volume=2.0)
                    voice.play(audio_source, after=None)
                    while voice.is_playing():
                        await sleep(1)
                    await voice.disconnect()
                    break
            x += 1
            print(x)
        if 'BY' in word.upper() or 'BE' in word.upper():
            voice_channel = None
            if message.author.voice and message.author.voice.channel:
                voice_channel = message.author.voice.channel
            if voice_channel != None:
                guild = message.guild
                voice = discord.utils.get(client.voice_clients, guild=guild)
                # if it is already connected to a channel then just move it, else connect
                if voice and voice.is_connected():
                    await voice.move_to(voice_channel)
                else:
                    voice = await voice_channel.connect()
                audio_source = discord.FFmpegPCMAudio('letsgo.mp3')
                if not voice.is_playing():
                        voice.play(audio_source, after=None)
                        await message.channel.send(file=discord.File('DaBaby.jpg'))
                        await message.channel.send('did someone say DaBaby?')
                        while voice.is_playing():
                            await sleep(1)
                        await voice.disconnect()
                        break
    file.close()
    file = open('count.txt', 'w')
    file.write(str(x))
    if '!nigga' in message.content:
        await message.channel.send('the n word has been said: ' + str(x) + ' times')

client.run('TOKEN GOES HERE')
