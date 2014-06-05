// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014 The AditiCoin Developers

// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "assert.h"
#include "core.h"
#include "protocol.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

/////////////////
// Main network
/////////////////

unsigned int pnSeed[] =
{
//    0x13f5094c, 0x7ab32648, 0x542e9fd5, 0x53136bc1, 0x7fdf51c0, 0x802197b2, 0xa2d2cc5b, 0x6b5f4bc0,
};

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        vAlertPubKey = ParseHex("048A3F78EC3020A09250B3CC20FBF638631BB61550B331CAFFF31F80694D0FA79A2B6931D8BEC0037533D8AA6B59B6390D888E30E799A1640DD7B2A4A3CF41998A");
        nDefaultPort = 8886;
        nRPCPort = 6213;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        nSubsidyInterval = 300000; 
        nBaseHeight =  10000; 
        nMinReward = 1500; 
        nMinNFactor = 10; 
        nMaxNFactor = 25;
        nStartTime = 1330477500; // 29 Feb 2012 leap year
        nLeap = 126230400; // 4 year leap
	nXadProp= 5;
	nSubsidy= 150000;
        vXadAddress.push_back("ALTEL4dK95MAmREeL7TZruA645ew1EKiJM");
        vXadAddress.push_back("ALUpuQ1rnUeho1yrZZfEXnWMpZ3skUcT2p");
        vXadAddress.push_back("AZcSLkfyHqWZTg3pU98AQpnjUkLCozKSZS");
        vXadAddress.push_back("ALLtjsbt3hFVJk8sDLnE7eTjW8Wjqx7t4e");
        vXadAddress.push_back("AddPyN9TDzX8kCGysGoSZqe5Dis7rNtXrM");

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        //
        // CBlock(hash=f0d52aaac1d6b1779baf11f7b763cf95f27183d77c2988ae9111473c6099f4b9, PoW=00000b256bc243ab0868, nFactor=10 ver=1, hashPrevBlock=00000,
        // hashMerkleRoot=dfa581bb7e3039782b92f3dc95e9037f3d8d6dc29c24995ae12f80943d111450, nTime=1402535100, nBits=1e0ffff0, nNonce=399113175, vtx=1)
        // CTransaction(hash=dfa581bb7e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        // CTxIn(COutPoint(0000000000, 4294967295), coinbase 04ffff001d010434544f49203237204d617920323031342c204e6172656e647261204d6f64692074616b6573206f617468206173203135746820504d)
        // CTxOut(nValue=1.000, scriptPubKey=04d323f0918b1de400b973ff79a838)
        // vMerkleTree: dfa581bb7e3039782b92f3dc95e9037f3d8d6dc29c24995ae12f80943d111450 

        const char* pszTimestamp = "TOI 27 May 2014, Narendra Modi takes oath as 15th PM"; //http://timesofindia.indiatimes.com/videos/news/Narendra-Modi-takes-oath-as-15th-PM/videoshow/35620429.cms
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CBigNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 1 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04D323F0918B1DE400B973FF79A838E97421B30078A88BEE72C9E63DDD35E66E94CE01B684BF23C73DBA22FF34DD528945BED2AED7EEDF92DAE3B55378EC4D4BDB") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1402535100;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 399113175;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0xf0d52aaac1d6b1779baf11f7b763cf95f27183d77c2988ae9111473c6099f4b9")); //Deva comment this while mining Genesis
        assert(genesis.hashMerkleRoot == uint256("0xdfa581bb7e3039782b92f3dc95e9037f3d8d6dc29c24995ae12f80943d111450"));

        vSeeds.push_back(CDNSSeedData("xad.aditicoin.org", "seed.vps.aditicoin.org"));
       
        /*vSeeds.push_back(CDNSSeedData("dashjr.org", "dnsseed.bitcoin.dashjr.org"));
        vSeeds.push_back(CDNSSeedData("bitcoinstats.com", "seed.bitcoinstats.com"));
        vSeeds.push_back(CDNSSeedData("xf2.org", "bitseed.xf2.org")); */

        base58Prefixes[PUBKEY_ADDRESS] = list_of(23); //XAD public key starts with "A" 23 
        base58Prefixes[SCRIPT_ADDRESS] = list_of(5); 
        base58Prefixes[SECRET_KEY] =     list_of(152); //  "P" 
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);

        // Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            // It'll only connect to one or two seed nodes because once it connects,
            // it'll get a pile of addresses with newer timestamps.
            // Seed nodes are given a random 'last seen time' of between one and two
            // weeks ago.
            const int64_t nOneWeek = 7*24*60*60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
            vFixedSeeds.push_back(addr);
        }
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


///////////////////////
// Testnet (v3)
///////////////////////
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x0c;
        pchMessageStart[1] = 0x12;
        pchMessageStart[2] = 0x0a;
        pchMessageStart[3] = 0x08;
        vAlertPubKey = ParseHex("0424A51BC048D8248D61C9D1370DAF65EC5DF2C2E8CD06282DDA0D71C8EA35B29C3661DF7E359A90B64A564112B431197C26B9912266660F03398A6077DB1D56A3");
        nDefaultPort = 18886;
        nRPCPort = 16213;
        strDataDir = "testnet3";
        vXadAddress.clear(); 		
        vXadAddress.push_back("DUSzgRXfp76EkMP56ghh3VaK6YaLxwkFhW");
        vXadAddress.push_back("DEhdhQp7dg5Vk7rtJqtsCbJvbhy9FJaUGQ");
		
        // CBlock(hash=7f487a32909a97d960d5fb287c97749ab0b97a09b5474675ab30b50ca3b0458e, PoW=000003f9a2070a6f955a, nFactor=10 ver=1, hashPrevBlock=00000
        // hashMerkleRoot=dfa581bb7e3039782b92f3dc95e9037f3d8d6dc29c24995ae12f80943d111450, nTime=1402103100, nBits=1e0ffff0, nNonce=408759439, vtx=1)
        // CTransaction(hash=dfa581bb7e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        // CTxIn(COutPoint(0000000000, 4294967295), coinbase 04ffff001d010434544f49203237204d617920323031342c204e6172656e647261204d6f64692074616b6573206f617468206173203135746820504d)
        // CTxOut(nValue=1.000, scriptPubKey=04d323f0918b1de400b973ff79a838)
        // vMerkleTree: dfa581bb7e3039782b92f3dc95e9037f3d8d6dc29c24995ae12f80943d111450 

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1402103100;
        genesis.nNonce = 408759439;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x7f487a32909a97d960d5fb287c97749ab0b97a09b5474675ab30b50ca3b0458e")); //DEVA Comment this while mining Genesis block

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("xad.aditicoin.org", "seed.vps.aditicoin.org"));


        base58Prefixes[PUBKEY_ADDRESS] = list_of(30); // DEVA D = 30 
        base58Prefixes[SCRIPT_ADDRESS] = list_of(196); 
        base58Prefixes[SECRET_KEY]     = list_of(118); // J = 118
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfb;
        pchMessageStart[1] = 0xc0;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0xdb;
	nSubsidyInterval = 1500; // Deva: 1K blocks
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
		
    // CBlock(hash=dc8c455c807db40624589593c2e33191b00bdb0295b061f0ccb3323526c73561, PoW=73d7b6892356e9ea0068, nFactor=10 ver=1, hashPrevBlock=00000 
    // hashMerkleRoot=dfa581bb7e3039782b92f3dc95e9037f3d8d6dc29c24995ae12f80943d111450, nTime=1401919812, nBits=207fffff, nNonce=1, vtx=1)
    // CTransaction(hash=dfa581bb7e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
    // CTxIn(COutPoint(0000000000, 4294967295), coinbase 04ffff001d010434544f49203237204d617920323031342c204e6172656e647261204d6f64692074616b6573206f617468206173203135746820504d)
    // CTxOut(nValue=1.000, scriptPubKey=04d323f0918b1de400b973ff79a838)
    // vMerkleTree: dfa581bb7e3039782b92f3dc95e9037f3d8d6dc29c24995ae12f80943d111450 
    
        genesis.nTime = 1401919812;
        genesis.nBits = 0x207fffff;
	//genesis.nBits = 0x207fffff;
        genesis.nNonce = 1;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 25213;
        strDataDir = "regtest";
	vXadAddress.clear(); 
        assert(hashGenesisBlock == uint256("0xdc8c455c807db40624589593c2e33191b00bdb0295b061f0ccb3323526c73561")); //DEVA Comment this while mining genesis block

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
