/* Machine generated file -- Do NOT edit */

#ifndef	_RXGEN_AFSCBINT_
#define	_RXGEN_AFSCBINT_

#ifdef	KERNEL
/* The following 'ifndefs' are not a good solution to the vendor's omission of surrounding all system includes with 'ifndef's since it requires that this file is included after the system includes...*/
#include <afsconfig.h>
#include "afs/param.h"
#ifdef	UKERNEL
#include "afs/sysincludes.h"
#include "rx/xdr.h"
#include "rx/rx.h"
#include "rx/rx_globals.h"
#else	/* UKERNEL */
#include "h/types.h"
#ifndef	SOCK_DGRAM  /* XXXXX */
#include "h/socket.h"
#endif
struct ubik_client;
#ifndef	DTYPE_SOCKET  /* XXXXX */
#ifndef AFS_LINUX22_ENV
#include "h/file.h"
#endif
#endif
#ifndef	S_IFMT  /* XXXXX */
#include "h/stat.h"
#endif
#if defined (AFS_OBSD_ENV) && !defined (MLEN)
#include "sys/mbuf.h"
#endif
#ifndef	IPPROTO_UDP /* XXXXX */
#include "netinet/in.h"
#endif
#ifndef	DST_USA  /* XXXXX */
#include "h/time.h"
#endif
#ifndef AFS_LINUX22_ENV
#include "rpc/types.h"
#endif /* AFS_LINUX22_ENV */
#ifndef	XDR_GETLONG /* XXXXX */
#ifdef AFS_LINUX22_ENV
#ifndef quad_t
#define quad_t __quad_t
#define u_quad_t __u_quad_t
#endif
#endif
#include "rx/xdr.h"
#endif /* XDR_GETLONG */
#endif   /* UKERNEL */
#include "afs/rxgen_consts.h"
#include "afs_osi.h"
#include "rx/rx.h"
#include "rx/rx_globals.h"
#else	/* KERNEL */
#include <afs/param.h>
#include <afs/stds.h>
#include <sys/types.h>
#include <rx/xdr.h>
#include <rx/rx.h>
#include <rx/rx_globals.h>
#include <afs/rxgen_consts.h>
#endif	/* KERNEL */

#ifdef AFS_NT40_ENV
#ifndef AFS_RXGEN_EXPORT
#define AFS_RXGEN_EXPORT __declspec(dllimport)
#endif /* AFS_RXGEN_EXPORT */
#else /* AFS_NT40_ENV */
#define AFS_RXGEN_EXPORT
#endif /* AFS_NT40_ENV */

#ifndef FSINT_COMMON_XG

struct AFSFid {
	afs_uint32 Volume;
	afs_uint32 Vnode;
	afs_uint32 Unique;
};
typedef struct AFSFid AFSFid;
bool_t xdr_AFSFid(XDR *xdrs, AFSFid *objp);


struct AFSCallBack {
	afs_uint32 CallBackVersion;
	afs_uint32 ExpirationTime;
	afs_uint32 CallBackType;
};
typedef struct AFSCallBack AFSCallBack;
bool_t xdr_AFSCallBack(XDR *xdrs, AFSCallBack *objp);


struct AFSDBLockDesc {
	char waitStates;
	char exclLocked;
	short readersReading;
	short numWaiting;
	short spare;
	int pid_last_reader;
	int pid_writer;
	int src_indicator;
};
typedef struct AFSDBLockDesc AFSDBLockDesc;
bool_t xdr_AFSDBLockDesc(XDR *xdrs, AFSDBLockDesc *objp);


struct AFSDBCacheEntry {
	afs_int32 addr;
	afs_int32 cell;
	AFSFid netFid;
	afs_int32 Length;
	afs_int32 DataVersion;
	struct AFSDBLockDesc lock;
	afs_int32 callback;
	afs_int32 cbExpires;
	short refCount;
	short opens;
	short writers;
	char mvstat;
	char states;
};
typedef struct AFSDBCacheEntry AFSDBCacheEntry;
bool_t xdr_AFSDBCacheEntry(XDR *xdrs, AFSDBCacheEntry *objp);


struct AFSDBCacheEntry64 {
	afs_int32 addr;
	afs_int32 cell;
	AFSFid netFid;
	afs_int64 Length;
	afs_int32 DataVersion;
	struct AFSDBLockDesc lock;
	afs_int32 callback;
	afs_int32 cbExpires;
	short refCount;
	short opens;
	short writers;
	char mvstat;
	char states;
};
typedef struct AFSDBCacheEntry64 AFSDBCacheEntry64;
bool_t xdr_AFSDBCacheEntry64(XDR *xdrs, AFSDBCacheEntry64 *objp);


struct AFSDBLock {
	char name[16];
	struct AFSDBLockDesc lock;
};
typedef struct AFSDBLock AFSDBLock;
bool_t xdr_AFSDBLock(XDR *xdrs, AFSDBLock *objp);


struct AFSDEntry {
	afs_int32 addr;
	afs_int32 cell;
	AFSFid netFid;
	afs_int32 Length;
	afs_int32 DataVersion;
	struct AFSDBLockDesc lock;
	afs_int32 callback;
	afs_int32 cbExpires;
	short refCount;
	short opens;
	short writers;
	char mvstat;
	char states;
};
typedef struct AFSDEntry AFSDEntry;
bool_t xdr_AFSDEntry(XDR *xdrs, AFSDEntry *objp);

#define CB_EXCLUSIVE 1
#define CB_SHARED 2
#define CB_DROPPED 3
#define AFSNAMEMAX 256
#define AFSPATHMAX 1024
#define AFSOPAQUEMAX 1024

typedef struct AFSOpaque {
	u_int AFSOpaque_len;
	char *AFSOpaque_val;
} AFSOpaque;
bool_t xdr_AFSOpaque(XDR *xdrs, AFSOpaque *objp);

#define AFSCBMAX 50

typedef struct AFSCBFids {
	u_int AFSCBFids_len;
	AFSFid *AFSCBFids_val;
} AFSCBFids;
bool_t xdr_AFSCBFids(XDR *xdrs, AFSCBFids *objp);


typedef struct AFSCBs {
	u_int AFSCBs_len;
	AFSCallBack *AFSCBs_val;
} AFSCBs;
bool_t xdr_AFSCBs(XDR *xdrs, AFSCBs *objp);

#define AFSCB_XSTAT_VERSION 2
#define AFS_XSTAT_VERSION 2
#define AFSCB_MAX_XSTAT_LONGS 2048
#define AFS_MAX_XSTAT_LONGS 1024

typedef struct AFSCB_CollData {
	u_int AFSCB_CollData_len;
	afs_int32 *AFSCB_CollData_val;
} AFSCB_CollData;
bool_t xdr_AFSCB_CollData(XDR *xdrs, AFSCB_CollData *objp);


typedef struct AFS_CollData {
	u_int AFS_CollData_len;
	afs_int32 *AFS_CollData_val;
} AFS_CollData;
bool_t xdr_AFS_CollData(XDR *xdrs, AFS_CollData *objp);

#define AFSCB_XSTATSCOLL_CALL_INFO 0
#define AFSCB_XSTATSCOLL_PERF_INFO 1
#define AFSCB_XSTATSCOLL_FULL_PERF_INFO 2
#define AFS_XSTATSCOLL_CALL_INFO 0
#define AFS_XSTATSCOLL_PERF_INFO 1
#define AFS_XSTATSCOLL_FULL_PERF_INFO 2
#define AFS_XSTATSCOLL_CBSTATS 3

typedef afs_uint32 VolumeId;
bool_t xdr_VolumeId(XDR *xdrs, VolumeId *objp);


typedef afs_uint32 VolId;
bool_t xdr_VolId(XDR *xdrs, VolId *objp);


typedef afs_uint32 VnodeId;
bool_t xdr_VnodeId(XDR *xdrs, VnodeId *objp);


typedef afs_uint32 Unique;
bool_t xdr_Unique(XDR *xdrs, Unique *objp);


typedef afs_uint32 UserId;
bool_t xdr_UserId(XDR *xdrs, UserId *objp);


typedef afs_uint32 FileVersion;
bool_t xdr_FileVersion(XDR *xdrs, FileVersion *objp);


typedef afs_int32 ErrorCode;
bool_t xdr_ErrorCode(XDR *xdrs, ErrorCode *objp);


typedef afs_int32 Rights;
bool_t xdr_Rights(XDR *xdrs, Rights *objp);

#define AFS_DISKNAMESIZE 32

typedef char DiskName[AFS_DISKNAMESIZE];
bool_t xdr_DiskName(XDR *xdrs, DiskName *objp);

#define CALLBACK_VERSION 1
#define AFS_MAX_INTERFACE_ADDR 32

struct interfaceAddr {
	int numberOfInterfaces;
	afsUUID uuid;
	afs_int32 addr_in[AFS_MAX_INTERFACE_ADDR];
	afs_int32 subnetmask[AFS_MAX_INTERFACE_ADDR];
	afs_int32 mtu[AFS_MAX_INTERFACE_ADDR];
};
typedef struct interfaceAddr interfaceAddr;
bool_t xdr_interfaceAddr(XDR *xdrs, interfaceAddr *objp);

#define AFSMAXCELLHOSTS 8

typedef struct serverList {
	u_int serverList_len;
	afs_int32 *serverList_val;
} serverList;
bool_t xdr_serverList(XDR *xdrs, serverList *objp);


typedef struct cacheConfig {
	u_int cacheConfig_len;
	afs_uint32 *cacheConfig_val;
} cacheConfig;
bool_t xdr_cacheConfig(XDR *xdrs, cacheConfig *objp);

#define AFSCAPABILITIESMAX 196

typedef struct Capabilities {
	u_int Capabilities_len;
	afs_uint32 *Capabilities_val;
} Capabilities;
bool_t xdr_Capabilities(XDR *xdrs, Capabilities *objp);

#define VICED_CAPABILITY_ERRORTRANS 0x0001
#define VICED_CAPABILITY_64BITFILES 0x0002
#define VICED_CAPABILITY_WRITELOCKACL 0x0004
#define VICED_CAPABILITY_SANEACLS 0x0008
#define CLIENT_CAPABILITY_ERRORTRANS 0x0001
#endif /* FSINT_COMMON_XG */
#define RXAFSCB_STATINDEX 6

#include <rx/rx_multi.h>
#define multi_RXAFSCB_CallBack(Fids_Array, CallBacks_Array) \
	multi_Body(StartRXAFSCB_CallBack(multi_call, Fids_Array, CallBacks_Array), EndRXAFSCB_CallBack(multi_call))


extern int StartRXAFSCB_CallBack(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSCBFids * Fids_Array,
	/*IN */ AFSCBs * CallBacks_Array);

extern int EndRXAFSCB_CallBack(
	/*IN */ struct rx_call *z_call);

extern int RXAFSCB_CallBack(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSCBFids * Fids_Array,
	/*IN */ AFSCBs * CallBacks_Array);

extern afs_int32 SRXAFSCB_CallBack(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSCBFids * Fids_Array,
	/*IN */ AFSCBs * CallBacks_Array);

extern int RXAFSCB_InitCallBackState(
	/*IN */ struct rx_connection *z_conn);

extern afs_int32 SRXAFSCB_InitCallBackState(
	/*IN */ struct rx_call *z_call);

#define multi_RXAFSCB_Probe() \
	multi_Body(StartRXAFSCB_Probe(multi_call), EndRXAFSCB_Probe(multi_call))


extern int StartRXAFSCB_Probe(
	/*IN */ struct rx_call *z_call);

extern int EndRXAFSCB_Probe(
	/*IN */ struct rx_call *z_call);

extern int RXAFSCB_Probe(
	/*IN */ struct rx_connection *z_conn);

extern afs_int32 SRXAFSCB_Probe(
	/*IN */ struct rx_call *z_call);

extern int RXAFSCB_GetLock(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 index,
	/*OUT*/ AFSDBLock * lock);

extern afs_int32 SRXAFSCB_GetLock(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 index,
	/*OUT*/ AFSDBLock * lock);

extern int RXAFSCB_GetCE(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 index,
	/*OUT*/ AFSDBCacheEntry * ce);

extern afs_int32 SRXAFSCB_GetCE(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 index,
	/*OUT*/ AFSDBCacheEntry * ce);

extern int RXAFSCB_XStatsVersion(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ afs_int32 * versionNumberP);

extern afs_int32 SRXAFSCB_XStatsVersion(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_int32 * versionNumberP);

extern int RXAFSCB_GetXStats(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 clientVersionNumber,
	/*IN */ afs_int32 collectionNumber,
	/*OUT*/ afs_int32 * srvVersionNumberP,
	/*OUT*/ afs_int32 * timeP,
	/*OUT*/ AFSCB_CollData * dataP);

extern afs_int32 SRXAFSCB_GetXStats(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 clientVersionNumber,
	/*IN */ afs_int32 collectionNumber,
	/*OUT*/ afs_int32 * srvVersionNumberP,
	/*OUT*/ afs_int32 * timeP,
	/*OUT*/ AFSCB_CollData * dataP);

extern int RXAFSCB_InitCallBackState2(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ struct interfaceAddr * addr);

extern afs_int32 SRXAFSCB_InitCallBackState2(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ struct interfaceAddr * addr);

extern int RXAFSCB_WhoAreYou(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ struct interfaceAddr * addr);

extern afs_int32 SRXAFSCB_WhoAreYou(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ struct interfaceAddr * addr);

extern int RXAFSCB_InitCallBackState3(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afsUUID * serverUuid);

extern afs_int32 SRXAFSCB_InitCallBackState3(
	/*IN */ struct rx_call *z_call,
	/*IN */ afsUUID * serverUuid);

#define multi_RXAFSCB_ProbeUuid(clientUuid) \
	multi_Body(StartRXAFSCB_ProbeUuid(multi_call, clientUuid), EndRXAFSCB_ProbeUuid(multi_call))


extern int StartRXAFSCB_ProbeUuid(
	/*IN */ struct rx_call *z_call,
	/*IN */ afsUUID * clientUuid);

extern int EndRXAFSCB_ProbeUuid(
	/*IN */ struct rx_call *z_call);

extern int RXAFSCB_ProbeUuid(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afsUUID * clientUuid);

extern afs_int32 SRXAFSCB_ProbeUuid(
	/*IN */ struct rx_call *z_call,
	/*IN */ afsUUID * clientUuid);

extern int RXAFSCB_GetServerPrefs(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 serverIndex,
	/*OUT*/ afs_int32 * srvrAddr,
	/*OUT*/ afs_int32 * srvrRank);

extern afs_int32 SRXAFSCB_GetServerPrefs(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 serverIndex,
	/*OUT*/ afs_int32 * srvrAddr,
	/*OUT*/ afs_int32 * srvrRank);

extern int RXAFSCB_GetCellServDB(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 cellIndex,
	/*OUT*/ char * *cellName,
	/*OUT*/ serverList * cellHosts);

extern afs_int32 SRXAFSCB_GetCellServDB(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 cellIndex,
	/*OUT*/ char * *cellName,
	/*OUT*/ serverList * cellHosts);

extern int RXAFSCB_GetLocalCell(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ char * *cellName);

extern afs_int32 SRXAFSCB_GetLocalCell(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ char * *cellName);

extern int RXAFSCB_GetCacheConfig(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 callerVersion,
	/*OUT*/ afs_uint32 * serverVersion,
	/*OUT*/ afs_uint32 * configCount,
	/*OUT*/ cacheConfig * config);

extern afs_int32 SRXAFSCB_GetCacheConfig(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 callerVersion,
	/*OUT*/ afs_uint32 * serverVersion,
	/*OUT*/ afs_uint32 * configCount,
	/*OUT*/ cacheConfig * config);

extern int RXAFSCB_GetCE64(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 index,
	/*OUT*/ AFSDBCacheEntry64 * ce);

extern afs_int32 SRXAFSCB_GetCE64(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 index,
	/*OUT*/ AFSDBCacheEntry64 * ce);

extern int RXAFSCB_GetCellByNum(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 cellNumber,
	/*OUT*/ char * *cellName,
	/*OUT*/ serverList * cellHosts);

extern afs_int32 SRXAFSCB_GetCellByNum(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 cellNumber,
	/*OUT*/ char * *cellName,
	/*OUT*/ serverList * cellHosts);

extern int RXAFSCB_TellMeAboutYourself(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ struct interfaceAddr * addr,
	/*OUT*/ Capabilities * capabilities);

extern afs_int32 SRXAFSCB_TellMeAboutYourself(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ struct interfaceAddr * addr,
	/*OUT*/ Capabilities * capabilities);

extern int RXAFSCB_ExecuteRequest(struct rx_call *);

/* Opcode-related useful stats for package: RXAFSCB_ */
#define RXAFSCB_LOWEST_OPCODE   204
#define RXAFSCB_HIGHEST_OPCODE	65538
#define RXAFSCB_NUMBER_OPCODES	18

#define RXAFSCB_NO_OF_STAT_FUNCS	18

AFS_RXGEN_EXPORT
extern const char *RXAFSCB_function_names[];

#endif	/* _RXGEN_AFSCBINT_ */
