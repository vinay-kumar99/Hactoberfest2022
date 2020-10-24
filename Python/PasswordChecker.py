# this file is able to tell you you're password was pwned or not withowt sharing your password with anyone
import requests
import hashlib
import sys


def rad(query_char):
    #rad **STANDS FOR** request api data
    url = 'https://api.pwnedpasswords.com/range/' + query_char
    res = requests.get(url)
    if res.status_code != 200:
        raise RuntimeError("Error fetching {}, check the api and try again".format(res.status_code))
    return res


def get_password_leak_count(hashes, charsAfterFirst5):
    hashes = (line.split(':') for line in hashes.text.splitlines())
    for h, count in hashes:
        if h == charsAfterFirst5:
            return count
    return 0


def pac(password):
    #pac **STANDS FOR** pwned api check
    sha1password = hashlib.sha1(password.encode('utf-8')).hexdigest().upper()
    first5char, tail = sha1password[:5], sha1password[5:]
    response = rad(first5char)
    return get_password_leak_count(response, tail)


def main(args):
    count = pac(args)
    if count:
        print("{} was found {} times, you must change your password.".format(args, count))
    else:
        print("your password was not found, keep it up")
    return 'done!'


if __name__ == "__main__":
     pswd = input("please enter your password: ")
     sys.exit(main(pswd))

