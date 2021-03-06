#ifndef CAT_CLIENT_C_CLIENT_CONFIG_H
#define CAT_CLIENT_C_CLIENT_CONFIG_H

#include "client.h"

#include "lib/cat_sds.h"

#define catChecktPtr(ptr) catChecktPtrWithName((ptr), (#ptr))

typedef struct _CatClientInnerConfig {
    sds appkey;
    sds selfHost;
    sds serverHost;

    sds defaultIp;
    sds defaultIpHex;

    unsigned int serverPort;
    int serverNum;
    sds *serverAddresses;

    int messageEnableFlag;
    int messageQueueSize;
    int messageQueueBlockPrintCount;
    int maxChildSize;
    int maxContextElementSize;

    int logFlag;
    int logSaveFlag;
    int logDebugFlag;
    int logFileWithTime;
    int logFilePerDay;
    int logLevel;

    sds configDir;
    sds dataDir;
    sds indexFileName;

    int encoderType;
    volatile int enableHeartbeat;
    volatile int enableSampling;
    volatile int enableMultiprocessing;
} CatClientInnerConfig;

#define DEFAULT_APPKEY "cat"
#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_IP_HEX "7f000001"

#define DEFAULT_XML_FILE "/data/appdatas/cat/client.xml"

#if defined(__linux__) || defined(__APPLE__)
#define DEFAULT_DATA_DIR "/data/appdatas/cat/"
#else
#define DEFAULT_DATA_DIR "./"
#endif

extern CatClientInnerConfig g_config;

int loadCatClientConfig(const char *filename);

void initCatClientConfig(CatClientConfig *config);

void clearCatClientConfig();

void catChecktPtrWithName(void *ptr, char *ptrName);

#endif //CAT_CLIENT_C_CLIENT_CONFIG_H
