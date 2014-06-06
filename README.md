Aditicoin Core integration/staging tree
=====================================

http://www.aditicoin.com

Copyright (c) 2014 AditiCoin Core Developers

What is AditiCoin?
------------------

AditiCoin is an experimental new digital currency that enables instant payments to
anyone, anywhere in the world. AditiCoin uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. AditiCoin Core is the name of open source
software which enables the use of this currency.

AditiCoin is forked from [Bitcoin](https://github.com/bitcoin). It can be efficiently mined with consumer-grade hardware. AditiCoin uses scrypt-jane library (Keccak512 and ChaCha20/8) with modified N-factor as block hashing algorithm, where N-factor starts at 10 and increases every 4 year on 29 Feb, till it reaches 25.

For more information, as well as an immediately useable, binary version of
the AditiCoin Core software, see http://www.bitcoin.com/download.

License
-------

AditiCoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see http://opensource.org/licenses/MIT.


Scrypt-Jane Adaptive N-Factor
-----------------------------

Scrypt Jane is a modern twist on the traditional Scrypt mining using a combination of 3 mixing functions and 7 hashing functions. Scrypt Jane refers to a group of mixing and hashing function. For more info Visit https://github.com/floodyberry/scrypt-jane.

Traditional Scrypt coins use a fixed Scrypt(1024, 1, 1) mixing Salsa and hashing with SHA-256 . These functions use only 128 kB of memory per hash and can effectively be mined by GPU's.

Scrypt-Jane uses Scrypt(N, 1, 1), with the N parameter increasing over time. Unlike Scrypt which uses Sha256, Scrypt-Jane offers several fast and secure alternate hashing functions, out of which AditiCoin uses Keccak512 as hashing function and ChaCha20/8 as Mixing Function.

Scrypt-Jane uses an N-Factor (N, 1, 1), that number determines the amount of memory required to solve a share. This N-Factor number will increase over time, usually at regular intervals in the blockchain. in case of AditiCoin, every 4 years on 29th February. As the N-Factor number increases, the mining efficiency will become lower, as the amount of memory needed for each share is increased. The current N-Factor can be shown by typing getmininginfo into the console. This also displays the current amount of memory needed.

AditiCoin was intended to be mined on CPU’s only. But it can be mined on GPU as well, although these miners are an advantage in the beginning, they soon become less effective as the N-Factor increases, increasing memory making GPU mining less efficient.

Scrypt-Jane offer a far greater network security, mining efficiency, ASIC resistance and protection.

Reduction in Decimal Places
---------------------------

Research on pricing psychology suggests that numbers and their arrangement around the decimal place influence perceived value. As the eyes move left to right, digits to the left of the decimal place are most significant for us. This would give the user a larger nominal representation of wealth, fewer zeros to the left and a greater psychological satisfaction. Scientist and researcher Stanislas Dehaene notes that prices with precise numbers tend to make consumers uneasy.

As form of Digital Currency, any currency can have more than 2 decimal places. Bitcoin uses 8 decimal places, PPcoin uses 6 decimal places. AditiCoin has set decimal places to 3, if there is any amount at 4th decimal place onwards it will be automatically discarded and saved nearest 3 decimal places only. This will impact on size reduction in transactions and overall blockchain. There is good article to read about [The psychology of Decimals](http://bitcoinmagazine.com/8274/the-psychology-of-decimals/). If needed decimal places can be increased in near future.


DigiByte's DigiShield
---------------------

DigiShield re-targets a coin’s difficulty to protect against multi-pools and an over-inflation of easily mined new coins. DigiShield re-targets a coin’s difficulty between every block. You need to allow the difficulty to increase enough between blocks to catch up to a sudden spike in net hash, but not enough to accidentally send the difficulty sky high when two miners get lucky and find blocks back to back. The asymmetrical adjustments keep the difficulty from going to high to fast, but allow it to drop much quicker after a large hash down swing as it takes a much longer time to discover the next two blocks for the difficulty adjustment to occur. For further info visit: [What is DigiShield & How it Works to Retarget Difficulty](http://www.reddit.com/r/Digibyte/comments/213t7b/what_is_digishield_how_it_works_to_retarget/).


### Credits

Without following People, Developers & Websites this coin haven't been live, Thanks for their open-source code, and information because of which AditiCoin has launched. Deva have studied them while creating AditiCoin.

Subvolatil, Benson Samuel, Bitcoin Core Developers, Litecoin Developers, PPcoin, Devcoin, DigiByte, Novacoin, Vertcoin, Yacoin, Dogecoin, Megacoin, Maxcoin, Quarkcoin, microcoin, SecureCoin, NobleCoin, Darkcoin, Hirocoin, Worldcoin, Bitcointalk.org, coindesk.com, bitcoinmagazine.com. and last but not least Thanks to Mashable.com for introducing Deva to Bitcoin.
