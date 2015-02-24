#pragma once

#include <stdint.h>

/* XXX: Comment out this line for a non-test network */
//#define BTS_TEST_NETWORK

#define BTS_TEST_NETWORK_VERSION                            83 // autogenerated

#define BTS_BLOCKCHAIN_DATABASE_VERSION                     uint64_t( 199 )

#define BTS_ADDRESS_PREFIX                                  "DVS"
#define BTS_BLOCKCHAIN_SYMBOL                               "DVS"
#define BTS_BLOCKCHAIN_NAME                                 "DevShares"
#define BTS_BLOCKCHAIN_DESCRIPTION                          "BitShares Development Network"
#define BTS_BLOCKCHAIN_PRECISION                            100000

#define BTS_BLOCKCHAIN_MAX_UIA_MARKET_FEE                   10000
#define BTS_BLOCKCHAIN_BLOCK_INTERVAL_SEC                   int64_t(10)
#define BTS_BLOCKCHAIN_BLOCKS_PER_HOUR                      ((60*60)/BTS_BLOCKCHAIN_BLOCK_INTERVAL_SEC)
#define BTS_BLOCKCHAIN_BLOCKS_PER_DAY                       (BTS_BLOCKCHAIN_BLOCKS_PER_HOUR*int64_t(24))
#define BTS_BLOCKCHAIN_BLOCKS_PER_YEAR                      (BTS_BLOCKCHAIN_BLOCKS_PER_DAY*int64_t(365))

#define BTS_BLOCKCHAIN_NUM_DELEGATES                        uint32_t(101)
#define BTS_MAX_DELEGATE_PAY_PER_BLOCK                      int64_t( 500 * BTS_BLOCKCHAIN_PRECISION )
#define BTS_BLOCKCHAIN_MAX_UNDO_HISTORY                     BTS_BLOCKCHAIN_BLOCKS_PER_HOUR

#define BTS_BLOCKCHAIN_MAX_SLATE_SIZE                       (BTS_BLOCKCHAIN_NUM_DELEGATES + (BTS_BLOCKCHAIN_NUM_DELEGATES/10))
#define BTS_BLOCKCHAIN_MAX_TRANSACTION_EXPIRATION_SEC       (60*60*24*2)
#define BTS_BLOCKCHAIN_MAX_MEMO_SIZE                        19 // bytes
#define BTS_BLOCKCHAIN_EXTENDED_MEMO_SIZE                   32 // bytes
#define BTS_BLOCKCHAIN_MAX_EXTENDED_MEMO_SIZE               (BTS_BLOCKCHAIN_MAX_MEMO_SIZE + BTS_BLOCKCHAIN_EXTENDED_MEMO_SIZE)

/**
 *  The maximum amount that can be issued for user assets.
 *
 *  10^18 / 2^63 < 1  however, to support representing all share values as a double in
 *  languages like java script, we must stay within the epsilon so
 *
 *  10^15 / 2^53 < 1 allows all values to be represented as a double or an int64
 */
#define BTS_BLOCKCHAIN_MAX_SHARES                           (1000*1000*int64_t(1000)*1000*int64_t(1000))

#define BTS_BLOCKCHAIN_MIN_NAME_SIZE                        1
#define BTS_BLOCKCHAIN_MAX_NAME_SIZE                        63
#define BTS_BLOCKCHAIN_MAX_NAME_DATA_SIZE                   (1024*64)

#define BTS_BLOCKCHAIN_MAX_SUB_SYMBOL_SIZE                  8 // characters
#define BTS_BLOCKCHAIN_MIN_SYMBOL_SIZE                      3 // characters
#define BTS_BLOCKCHAIN_MAX_SYMBOL_SIZE                      12 // characters

#define BTS_BLOCKCHAIN_MIN_BURN_FEE                         BTS_BLOCKCHAIN_PRECISION * 1 // 1 XTS

#ifdef BTS_TEST_NETWORK
#define BTS_BLOCKCHAIN_VOTE_UPDATE_PERIOD_SEC               10
#else
#define BTS_BLOCKCHAIN_VOTE_UPDATE_PERIOD_SEC               (60*60) // 1 hour
#endif

#define BTS_BLOCKCHAIN_MIN_FEEDS                            ((BTS_BLOCKCHAIN_NUM_DELEGATES/2) + 1)
#define BTS_BLOCKCHAIN_MINIMUM_SHORT_ORDER_SIZE             (BTS_BLOCKCHAIN_PRECISION*100)
#define BTS_BLOCKCHAIN_MIN_YIELD_PERIOD_SEC                 (60*60*24) // 24 hours
#define BTS_BLOCKCHAIN_MAX_YIELD_PERIOD_SEC                 (BTS_BLOCKCHAIN_BLOCKS_PER_YEAR * BTS_BLOCKCHAIN_BLOCK_INTERVAL_SEC) // 1 year

#ifdef BTS_TEST_NETWORK
#define BTS_BLOCKCHAIN_MAX_SHORT_PERIOD_SEC                 (2*60*60) // 2 hours
#else
#define BTS_BLOCKCHAIN_MAX_SHORT_PERIOD_SEC                 (30*24*60*60) // 1 month
#endif

#define BTS_BLOCKCHAIN_MCALL_D2C_NUMERATOR                  1
#define BTS_BLOCKCHAIN_MCALL_D2C_DENOMINATOR                2

// TODO: This stuff only matters for propagation throttling; should go somewhere else
#define BTS_BLOCKCHAIN_DEFAULT_RELAY_FEE                    100000
#define BTS_BLOCKCHAIN_MAX_TRX_PER_SECOND                   1  // (10)
#define BTS_BLOCKCHAIN_MAX_PENDING_QUEUE_SIZE               10 // (BTS_BLOCKCHAIN_MAX_TRX_PER_SECOND * BTS_BLOCKCHAIN_BLOCK_INTERVAL_SEC)
