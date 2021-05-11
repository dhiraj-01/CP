import sublime_plugin, os
import random
from datetime import datetime

quotes = [
[
    "Power is not given to you. You have to take it.",
    "-- Beyonce"
],
[
    "Believe you can and you’re halfway there.",
    "-- Theodore Roosevelt"
],
[
    "Life is either a daring adventure, or nothing.",
    "-- Helen Keller"
],
[
    "By failing to prepare, you are preparing to fail.",
    "-- Benjamin Franklin"
],
[
    "You have power over your mind – not outside events. Realize this, and you will find strength."
    "-- Marcus Aurelius"
],
[
    "I fear not the man who has practiced 10,000 kicks once,",
    "but I fear the man who has practiced one kick 10,000 times.",
    "-- Bruce Lee"
],
[
    "The weak can never forgive. Forgiveness is the attribute of the strong.",
    "-- Mahatma Gandhi"
],
[
    "It always seems impossible until it’s done.",
    "-- Nelson Mandela"
],
[
    "Well done is better than well said.",
    "-- Benjamin Franklin"
],
[
    "The future belongs to those who prepare for it today.",
    "-- Malcolm X"
],
[
    "The most courageous act is still to think for yourself.",
    "-- Aloud. Coco"
],
[
    "Wisely, and slow. They stumble that run fast.",
    "-- William Shakespeare"
],
[
    "The successful warrior is the average man, with laser-like focus.",
    "-- Bruce Lee"
],
[
    "I don't measure a man's success by how high he climbs ,",
    "but how high he bounces when he hits bottom. ",
    "-- George S. Patton"

],
[
    "Always remember that you are absolutely unique. Just like everyone else.",
    "-- Margaret Mead"
],
[
    "Remember that the happiest people are not those getting more",
    "but those giving more.",
    "-- H. Jackson Brown"
],
[
    "When you consciously choose to be ordinary,",
    "You become extraordinary.",
    "-- Sadhguru"
],
[
    "Be happy for this moment. This moment is your life.",
    "-- Omar Khayyam"
],
[
    "Stress is not a natural part of life. Stress comes from your inability",
    "to manage your own system.",
    "-- Sadhguru"

],
[
    "Be the change that you wish to see in the world.",
    "-- Mahatma Gandhi"
],
[
    "Don't walk in front of me..  I may not follow",
    "Don't walk behind me..  I may not lead",
    "Walk beside me..  just be my friend",
    "-- Albert Camus"
],
[
    "All that we are is the result of what we have thought.",
    "-- Buddha"
],
[
    "Learn from yesterday, live for today, hope for tomorrow.",
    "The important thing is not to stop questioning.",
    "-- Albert Einstein"
],
[
    "The fear is simply because you are not living with life,",
    "You are living in your mind.",
    "-- Sadhguru"
],
[
    "The purpose of our lives is to be happy.",
    "-- Dalai Lama"
],
[
    "Whatever you are, be a good one.",
    "-- Abraham Lincoln"
],
[
    "When you talk, you are repeating what you already know.",
    "But if you listen, you may learn something new.",
    "-- Dalai Lama"
],
[
    "A fish with his mouth closed never gets caught.",
    "-- Tony Accardo"
],
[
    "Try not to become a man of success but rather to become a man of value.",
    "-- Albert Einstein"
],
[
    "Love the life you live. Live the life you love.",
    "-- Bob Marley"
],
[
    "I have not failed. I've just found 10,000 ways that won't work.",
    "-- Thomas Edison"
],
[
    "If you can't explain it simply, you don't understand it well enough.",
    "-- Albert Einstein"
],
[
    "You can't please everyone, and you can't make everyone like you.", 
    "-- Katie Couric"
],
[
    "Peace begins with a smile.",
    "-- Mother Teresa"
],
[
    "Success is most often achieved by those who don't know that failure is inevitable.",
    "-- Coco Chanel"
],
[
    "It does not matter how slowly you go, so long as you do not stop.",
    "-- Confucius"
],
[
    "Don't cry because it's over, smile because it happened.",
    "-- Dr. Seuss"
],
[
    "Be yourself. Everyone else is already taken.",
    "-- Oscar Wilde"
],
[
    "You only live once, but if you do it right, once is enough.", 
    "-- Mae West"
],
[
    "Your limitation it's only your imagination.",
],
[
    "The harder you work for something, the greater you'll feel when you achieve it.",
],
[
    "Don't stop when you're tired. Stop when you're done.",
],
[
    "Any fool can write code that a computer can understand.",
    "Good programmers write code that humans can understand.",
    "-- Martin Fowler"
],
[
    "The happiest moment i felt is that moment when i realized my ability to create.",
    "-- Dr. Hazem Ali"
],
[
    "Wake up with determination. Go to bed with satisfaction.",
],
[
    "Experience is the name everyone gives to their mistakes.",
    "-- Oscar Wilde"
],
[
    "Knowledge is power.",
    "-- Francis Bacon"
],
[
    "Do one thing every day that scares you.",
    "-- Eleanor Roosevelt"
],
[
    "Keep your face to the sunshine and you can never see the shadow.",
    "-- Helen Keller"
],
[
    "In order to be irreplaceable, one must always be different.",
    "-- Coco Chanel"
],
[
    "Simplicity is the soul of efficiency.",
    "-- Austin Freeman"
],
[
    "Act as if what you do makes a difference. It does.",
    "-- William James"
],
[
    "Life is like riding a bicycle. To keep your balance, you must keep moving.",
    "-- Albert Einstein"
],
[
    "Limit your \"always\" and your \"nevers\".",
    "-- Amy Poehler​​"
],
[
    "Make it work, make it right, make it fast.",
    "-- Kent Beck"
],
[
    "Inspiration comes from within yourself. One has to be positive.",
    "When you're positive, good things happen.",
    "-- Deep Roy"
],
[
    "You must do the things you think you cannot do.",
    "-- Eleanor Roosevelt"
],
[
    "Without great solitude, no serious work is possible.",
    "-- Pablo Picasso"
]
]

class QuoteCommand(sublime_plugin.TextCommand):
    def run(self, edit):

        now = datetime.now()
        cur_date = now.strftime("%d %B %Y ~ %A")
        cur_time = now.strftime("%I:%M:%S %p")
        
        # without quote
        info = '''/*
**    author : Dhiraj Govindvira
**      date : {}
**      time : {}
*/
\n'''.format(cur_date, cur_time)

        # with quote
#         ind = random.randrange(len(quotes))
#         info = '/*'
#         for q in quotes[ind]:
#             info += "\n**    " + q
#         info += '''
# **
# **    Author : Dhiraj Govindvira
# **      Date : {}
# **      Time : {}
# */\n'''.format(cur_date, cur_time)

        file_path = self.view.file_name()
        if(os.path.exists(file_path)):
            with open(file_path, "r") as file:
                myCode = file.readlines()

                # update
                if len(myCode) >= 6:
                    if myCode[1] == "**    author : Dhiraj Govindvira\n":
                        if myCode[5] == "\n":
                            myCode = myCode[6::]
                        else:
                            myCode = myCode[5::]

                code = ""
                for line in myCode:
                    code += line

                with open(file_path, "w", encoding = 'utf-8') as file:
                    file.write(info + code)
