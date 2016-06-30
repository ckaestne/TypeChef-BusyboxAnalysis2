/* Machine generated file -- Do NOT edit */

#ifndef	_RXGEN_AFSINT_
#define	_RXGEN_AFSINT_

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
#define VICECONNBAD 1234
#define VICETOKENDEAD 1235
#define AFS_LOCKWAIT (5*60)

struct CBS {
	afs_int32 SeqLen;
	char *SeqBody;
};
typedef struct CBS CBS;
bool_t xdr_CBS(XDR *xdrs, CBS *objp);


struct BBS {
	afs_int32 MaxSeqLen;
	afs_int32 SeqLen;
	char *SeqBody;
};
typedef struct BBS BBS;
bool_t xdr_BBS(XDR *xdrs, BBS *objp);


struct AFSAccessList {
	afs_int32 MaxSeqLen;
	afs_int32 SeqLen;
	char *SeqBody;
};
typedef struct AFSAccessList AFSAccessList;
bool_t xdr_AFSAccessList(XDR *xdrs, AFSAccessList *objp);


typedef afs_int32 ViceDataType;
bool_t xdr_ViceDataType(XDR *xdrs, ViceDataType *objp);

#define Invalid 0
#define File 1
#define Directory 2
#define SymbolicLink 3
#ifdef KERNEL
#define afs_xdr_array(a,b,c,d,e,f) afs_xdr_arrayN(a,b,c,d,e,f)
#endif

struct BD {
	afs_int32 host;
	afs_int32 portal;
	afs_int32 session;
};
typedef struct BD BD;
bool_t xdr_BD(XDR *xdrs, BD *objp);


struct AFSVolSync {
	afs_uint32 spare1;
	afs_uint32 spare2;
	afs_uint32 spare3;
	afs_uint32 spare4;
	afs_uint32 spare5;
	afs_uint32 spare6;
};
typedef struct AFSVolSync AFSVolSync;
bool_t xdr_AFSVolSync(XDR *xdrs, AFSVolSync *objp);


struct AFSOldFetchStatus {
	afs_uint32 InterfaceVersion;
	afs_uint32 FileType;
	afs_uint32 LinkCount;
	afs_uint32 Length;
	afs_uint32 DataVersion;
	afs_uint32 Author;
	afs_uint32 Owner;
	afs_uint32 CallerAccess;
	afs_uint32 AnonymousAccess;
	afs_uint32 UnixModeBits;
	afs_uint32 ParentVnode;
	afs_uint32 ParentUnique;
	afs_uint32 SegSize;
	afs_uint32 ClientModTime;
	afs_uint32 ServerModTime;
	afs_uint32 Group;
};
typedef struct AFSOldFetchStatus AFSOldFetchStatus;
bool_t xdr_AFSOldFetchStatus(XDR *xdrs, AFSOldFetchStatus *objp);


struct AFSFetchStatus {
	afs_uint32 InterfaceVersion;
	afs_uint32 FileType;
	afs_uint32 LinkCount;
	afs_uint32 Length;
	afs_uint32 DataVersion;
	afs_uint32 Author;
	afs_uint32 Owner;
	afs_uint32 CallerAccess;
	afs_uint32 AnonymousAccess;
	afs_uint32 UnixModeBits;
	afs_uint32 ParentVnode;
	afs_uint32 ParentUnique;
	afs_uint32 ResidencyMask;
	afs_uint32 ClientModTime;
	afs_uint32 ServerModTime;
	afs_uint32 Group;
	afs_uint32 SyncCounter;
	afs_uint32 dataVersionHigh;
	afs_uint32 lockCount;
	afs_uint32 Length_hi;
	afs_uint32 errorCode;
};
typedef struct AFSFetchStatus AFSFetchStatus;
bool_t xdr_AFSFetchStatus(XDR *xdrs, AFSFetchStatus *objp);


struct AFSStoreStatus {
	afs_uint32 Mask;
	afs_uint32 ClientModTime;
	afs_uint32 Owner;
	afs_uint32 Group;
	afs_uint32 UnixModeBits;
	afs_uint32 SegSize;
};
typedef struct AFSStoreStatus AFSStoreStatus;
bool_t xdr_AFSStoreStatus(XDR *xdrs, AFSStoreStatus *objp);

#define AFS_SETMODTIME 1
#define AFS_SETOWNER 2
#define AFS_SETGROUP 4
#define AFS_SETMODE 8
#define AFS_SETSEGSIZE 16
#define AFS_FSYNC 1024

typedef afs_int32 ViceVolumeType;
bool_t xdr_ViceVolumeType(XDR *xdrs, ViceVolumeType *objp);

#define ReadOnly 0
#define ReadWrite 1

struct ViceDisk {
	afs_int32 BlocksAvailable;
	afs_int32 TotalBlocks;
	DiskName Name;
};
typedef struct ViceDisk ViceDisk;
bool_t xdr_ViceDisk(XDR *xdrs, ViceDisk *objp);


struct ViceStatistics {
	afs_uint32 CurrentMsgNumber;
	afs_uint32 OldestMsgNumber;
	afs_uint32 CurrentTime;
	afs_uint32 BootTime;
	afs_uint32 StartTime;
	afs_int32 CurrentConnections;
	afs_uint32 TotalViceCalls;
	afs_uint32 TotalFetchs;
	afs_uint32 FetchDatas;
	afs_uint32 FetchedBytes;
	afs_int32 FetchDataRate;
	afs_uint32 TotalStores;
	afs_uint32 StoreDatas;
	afs_uint32 StoredBytes;
	afs_int32 StoreDataRate;
	afs_uint32 TotalRPCBytesSent;
	afs_uint32 TotalRPCBytesReceived;
	afs_uint32 TotalRPCPacketsSent;
	afs_uint32 TotalRPCPacketsReceived;
	afs_uint32 TotalRPCPacketsLost;
	afs_uint32 TotalRPCBogusPackets;
	afs_int32 SystemCPU;
	afs_int32 UserCPU;
	afs_int32 NiceCPU;
	afs_int32 IdleCPU;
	afs_int32 TotalIO;
	afs_int32 ActiveVM;
	afs_int32 TotalVM;
	afs_int32 EtherNetTotalErrors;
	afs_int32 EtherNetTotalWrites;
	afs_int32 EtherNetTotalInterupts;
	afs_int32 EtherNetGoodReads;
	afs_int32 EtherNetTotalBytesWritten;
	afs_int32 EtherNetTotalBytesRead;
	afs_int32 ProcessSize;
	afs_int32 WorkStations;
	afs_int32 ActiveWorkStations;
	afs_int32 Spare1;
	afs_int32 Spare2;
	afs_int32 Spare3;
	afs_int32 Spare4;
	afs_int32 Spare5;
	afs_int32 Spare6;
	afs_int32 Spare7;
	afs_int32 Spare8;
	ViceDisk Disk1;
	ViceDisk Disk2;
	ViceDisk Disk3;
	ViceDisk Disk4;
	ViceDisk Disk5;
	ViceDisk Disk6;
	ViceDisk Disk7;
	ViceDisk Disk8;
	ViceDisk Disk9;
	ViceDisk Disk10;
};
typedef struct ViceStatistics ViceStatistics;
bool_t xdr_ViceStatistics(XDR *xdrs, ViceStatistics *objp);


struct VolumeStatus {
	afs_int32 Vid;
	afs_int32 ParentId;
	char Online;
	char InService;
	char Blessed;
	char NeedsSalvage;
	afs_int32 Type;
	afs_int32 MinQuota;
	afs_int32 MaxQuota;
	afs_int32 BlocksInUse;
	afs_int32 PartBlocksAvail;
	afs_int32 PartMaxBlocks;
};
typedef struct VolumeStatus VolumeStatus;
bool_t xdr_VolumeStatus(XDR *xdrs, VolumeStatus *objp);


struct AFSFetchVolumeStatus {
	afs_int32 Vid;
	afs_int32 ParentId;
	char Online;
	char InService;
	char Blessed;
	char NeedsSalvage;
	afs_int32 Type;
	afs_int32 MinQuota;
	afs_int32 MaxQuota;
	afs_int32 BlocksInUse;
	afs_int32 PartBlocksAvail;
	afs_int32 PartMaxBlocks;
};
typedef struct AFSFetchVolumeStatus AFSFetchVolumeStatus;
bool_t xdr_AFSFetchVolumeStatus(XDR *xdrs, AFSFetchVolumeStatus *objp);


struct AFSStoreVolumeStatus {
	afs_int32 Mask;
	afs_int32 MinQuota;
	afs_int32 MaxQuota;
};
typedef struct AFSStoreVolumeStatus AFSStoreVolumeStatus;
bool_t xdr_AFSStoreVolumeStatus(XDR *xdrs, AFSStoreVolumeStatus *objp);

#define AFS_SETMINQUOTA 1
#define AFS_SETMAXQUOTA 2

struct AFSVolumeInfo {
	afs_uint32 Vid;
	afs_int32 Type;
	afs_uint32 Type0;
	afs_uint32 Type1;
	afs_uint32 Type2;
	afs_uint32 Type3;
	afs_uint32 Type4;
	afs_uint32 ServerCount;
	afs_uint32 Server0;
	afs_uint32 Server1;
	afs_uint32 Server2;
	afs_uint32 Server3;
	afs_uint32 Server4;
	afs_uint32 Server5;
	afs_uint32 Server6;
	afs_uint32 Server7;
	u_short Port0;
	u_short Port1;
	u_short Port2;
	u_short Port3;
	u_short Port4;
	u_short Port5;
	u_short Port6;
	u_short Port7;
};
typedef struct AFSVolumeInfo AFSVolumeInfo;
bool_t xdr_AFSVolumeInfo(XDR *xdrs, AFSVolumeInfo *objp);


struct VolumeInfo {
	afs_uint32 Vid;
	afs_int32 Type;
	afs_uint32 Type0;
	afs_uint32 Type1;
	afs_uint32 Type2;
	afs_uint32 Type3;
	afs_uint32 Type4;
	afs_uint32 ServerCount;
	afs_uint32 Server0;
	afs_uint32 Server1;
	afs_uint32 Server2;
	afs_uint32 Server3;
	afs_uint32 Server4;
	afs_uint32 Server5;
	afs_uint32 Server6;
	afs_uint32 Server7;
};
typedef struct VolumeInfo VolumeInfo;
bool_t xdr_VolumeInfo(XDR *xdrs, VolumeInfo *objp);


typedef afs_int32 ViceLockType;
bool_t xdr_ViceLockType(XDR *xdrs, ViceLockType *objp);


typedef struct AFSBulkStats {
	u_int AFSBulkStats_len;
	AFSFetchStatus *AFSBulkStats_val;
} AFSBulkStats;
bool_t xdr_AFSBulkStats(XDR *xdrs, AFSBulkStats *objp);

#define LockRead 0
#define LockWrite 1
#define LockExtend 2
#define LockRelease 3

typedef afs_int32 ViceOfflineType;
bool_t xdr_ViceOfflineType(XDR *xdrs, ViceOfflineType *objp);

#define NoSalvage 0
#define Salvage 1
#define MAXCMDINT64S 3
#define MAXCMDINT32S 200
#define MAXCMDCHARS 256
#define CMD_GETRESIDENCIES 1
#define CMD_CHANGERESIDENCIES 2
#define CMD_IMPORTRESIDENCIES 3
#define CMD_GETEXTVOLATTR 4
#define CMD_SETEXTVOLATTR 5
#define CMD_GETACCESSHISTORY 6
#define CMD_MIGRATEFILE 7
#define CMD_CHECKHSMMETADATA 8
#define CMD_FETCHSTATUS 9
#define VOLATTR_DESIREDRESIDENCYMASK 1
#define VOLATTR_UNDESIREDRESIDENCYMASK 2
#define VOLATTR_SETSPECIALACCESSFLAG 4

struct ExtendedVolAttrInputs {
	afs_uint32 Mask;
	afs_uint32 Volume;
	afs_uint32 DesiredResidencyMask;
	afs_uint32 Spare1[10];
	afs_uint32 UnDesiredResidencyMask;
	afs_uint32 Spare2[9];
	afs_uint32 SpecialAccessFlag;
};
typedef struct ExtendedVolAttrInputs ExtendedVolAttrInputs;
bool_t xdr_ExtendedVolAttrInputs(XDR *xdrs, ExtendedVolAttrInputs *objp);


struct ExtendedVolAttrOutputs {
	afs_uint32 DesiredResidencyMask;
	afs_uint32 Spare1[10];
	afs_uint32 UnDesiredResidencyMask;
	afs_uint32 Spare2[9];
	afs_uint32 SpecialAccessFlag;
};
typedef struct ExtendedVolAttrOutputs ExtendedVolAttrOutputs;
bool_t xdr_ExtendedVolAttrOutputs(XDR *xdrs, ExtendedVolAttrOutputs *objp);


struct TagsArray {
	afs_uint32 TagsArray_len;
	afs_uint32 TagsArray_val[184];
};
typedef struct TagsArray TagsArray;
bool_t xdr_TagsArray(XDR *xdrs, TagsArray *objp);


struct AccessHistory {
	afs_uint64 Size;
	afs_uint32 ModTime;
	afs_uint32 NonSpoolingFetches;
	afs_uint32 UserSpoolingFetches;
	afs_uint32 MigratorSpoolingFetches;
	afs_uint32 LastUserMigrationEvent;
	afs_uint32 MigrateMe;
	afs_uint32 Time0;
	afs_uint32 Type0;
	afs_uint32 LocalAccess0;
	afs_uint32 Residency0;
	afs_uint32 Time1;
	afs_uint32 Type1;
	afs_uint32 LocalAccess1;
	afs_uint32 Residency1;
	afs_uint32 Time2;
	afs_uint32 Type2;
	afs_uint32 LocalAccess2;
	afs_uint32 Residency2;
	afs_uint32 Time3;
	afs_uint32 Type3;
	afs_uint32 LocalAccess3;
	afs_uint32 Residency3;
	afs_uint32 Time4;
	afs_uint32 Type4;
	afs_uint32 LocalAccess4;
	afs_uint32 Residency4;
};
typedef struct AccessHistory AccessHistory;
bool_t xdr_AccessHistory(XDR *xdrs, AccessHistory *objp);


struct AccessHistoryOld {
	afs_uint32 Size;
	afs_uint32 ModTime;
	afs_uint32 NonSpoolingFetches;
	afs_uint32 UserSpoolingFetches;
	afs_uint32 MigratorSpoolingFetches;
	afs_uint32 LastUserMigrationEvent;
	afs_uint32 MigrateMe;
	afs_uint32 Time0;
	afs_uint32 Type0;
	afs_uint32 LocalAccess0;
	afs_uint32 Residency0;
	afs_uint32 Time1;
	afs_uint32 Type1;
	afs_uint32 LocalAccess1;
	afs_uint32 Residency1;
	afs_uint32 Time2;
	afs_uint32 Type2;
	afs_uint32 LocalAccess2;
	afs_uint32 Residency2;
	afs_uint32 Time3;
	afs_uint32 Type3;
	afs_uint32 LocalAccess3;
	afs_uint32 Residency3;
	afs_uint32 Time4;
	afs_uint32 Type4;
	afs_uint32 LocalAccess4;
	afs_uint32 Residency4;
};
typedef struct AccessHistoryOld AccessHistoryOld;
bool_t xdr_AccessHistoryOld(XDR *xdrs, AccessHistoryOld *objp);


struct FsCmdInputs {
	afs_int32 command;
	struct AFSFid fid;
	afs_int64 int64s[MAXCMDINT64S];
	afs_uint32 int32s[MAXCMDINT32S];
	char chars[MAXCMDCHARS];
};
typedef struct FsCmdInputs FsCmdInputs;
bool_t xdr_FsCmdInputs(XDR *xdrs, FsCmdInputs *objp);


struct FsCmdOutputs {
	afs_int32 code;
	struct AFSFetchStatus status;
	afs_int64 int64s[MAXCMDINT64S];
	afs_uint32 int32s[MAXCMDINT32S];
	char chars[MAXCMDCHARS];
};
typedef struct FsCmdOutputs FsCmdOutputs;
bool_t xdr_FsCmdOutputs(XDR *xdrs, FsCmdOutputs *objp);

#define ResidencyCmdInputs FsCmdInputs
#define ResidencyCmdOutputs FsCmdOutputs
#define FLUSHMAX 10

typedef struct ViceIds {
	u_int ViceIds_len;
	afs_int32 *ViceIds_val;
} ViceIds;
bool_t xdr_ViceIds(XDR *xdrs, ViceIds *objp);


typedef struct IPAddrs {
	u_int IPAddrs_len;
	afs_int32 *IPAddrs_val;
} IPAddrs;
bool_t xdr_IPAddrs(XDR *xdrs, IPAddrs *objp);

#define RXAFS_STATINDEX 7

extern int StartRXAFS_FetchData(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ afs_int32 Pos,
	/*IN */ afs_int32 Length);

extern int EndRXAFS_FetchData(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_FetchData(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ afs_int32 Pos,
	/*IN */ afs_int32 Length,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_FetchACL(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * Fid,
	/*OUT*/ AFSOpaque * AccessList,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_FetchACL(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*OUT*/ AFSOpaque * AccessList,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_FetchStatus(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * Fid,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_FetchStatus(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern int StartRXAFS_StoreData(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ AFSStoreStatus * InStatus,
	/*IN */ afs_uint32 Pos,
	/*IN */ afs_uint32 Length,
	/*IN */ afs_uint32 FileLength);

extern int EndRXAFS_StoreData(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_StoreData(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ AFSStoreStatus * InStatus,
	/*IN */ afs_uint32 Pos,
	/*IN */ afs_uint32 Length,
	/*IN */ afs_uint32 FileLength,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_StoreACL(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * Fid,
	/*IN */ AFSOpaque * AccessList,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_StoreACL(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ AFSOpaque * AccessList,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_StoreStatus(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * Fid,
	/*IN */ AFSStoreStatus * InStatus,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_StoreStatus(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ AFSStoreStatus * InStatus,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_RemoveFile(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_RemoveFile(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_CreateFile(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*IN */ AFSStoreStatus * InStatus,
	/*OUT*/ AFSFid * OutFid,
	/*OUT*/ AFSFetchStatus * OutFidStatus,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_CreateFile(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*IN */ AFSStoreStatus * InStatus,
	/*OUT*/ AFSFid * OutFid,
	/*OUT*/ AFSFetchStatus * OutFidStatus,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_Rename(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * OldDirFid,
	/*IN */ char * OldName,
	/*IN */ AFSFid * NewDirFid,
	/*IN */ char * NewName,
	/*OUT*/ AFSFetchStatus * OutOldDirStatus,
	/*OUT*/ AFSFetchStatus * OutNewDirStatus,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_Rename(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * OldDirFid,
	/*IN */ char * OldName,
	/*IN */ AFSFid * NewDirFid,
	/*IN */ char * NewName,
	/*OUT*/ AFSFetchStatus * OutOldDirStatus,
	/*OUT*/ AFSFetchStatus * OutNewDirStatus,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_Symlink(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*IN */ char * LinkContents,
	/*IN */ AFSStoreStatus * InStatus,
	/*OUT*/ AFSFid * OutFid,
	/*OUT*/ AFSFetchStatus * OutFidStatus,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_Symlink(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*IN */ char * LinkContents,
	/*IN */ AFSStoreStatus * InStatus,
	/*OUT*/ AFSFid * OutFid,
	/*OUT*/ AFSFetchStatus * OutFidStatus,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_Link(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*IN */ AFSFid * ExistingFid,
	/*OUT*/ AFSFetchStatus * OutFidStatus,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_Link(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*IN */ AFSFid * ExistingFid,
	/*OUT*/ AFSFetchStatus * OutFidStatus,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_MakeDir(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*IN */ AFSStoreStatus * InStatus,
	/*OUT*/ AFSFid * OutFid,
	/*OUT*/ AFSFetchStatus * OutFidStatus,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_MakeDir(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*IN */ AFSStoreStatus * InStatus,
	/*OUT*/ AFSFid * OutFid,
	/*OUT*/ AFSFetchStatus * OutFidStatus,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_RemoveDir(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_RemoveDir(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_OldSetLock(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * Fid,
	/*IN */ ViceLockType Type,
	/*IN */ AFSVolSync * Sync);

extern afs_int32 SRXAFS_OldSetLock(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ ViceLockType Type,
	/*IN */ AFSVolSync * Sync);

extern int RXAFS_OldExtendLock(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * Fid,
	/*IN */ AFSVolSync * Sync);

extern afs_int32 SRXAFS_OldExtendLock(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ AFSVolSync * Sync);

extern int RXAFS_OldReleaseLock(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * Fid,
	/*IN */ AFSVolSync * Sync);

extern afs_int32 SRXAFS_OldReleaseLock(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ AFSVolSync * Sync);

extern int RXAFS_GetStatistics(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ ViceStatistics * Statistics);

extern afs_int32 SRXAFS_GetStatistics(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ ViceStatistics * Statistics);

extern int RXAFS_GiveUpCallBacks(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSCBFids * Fids_Array,
	/*IN */ AFSCBs * CallBacks_Array);

extern afs_int32 SRXAFS_GiveUpCallBacks(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSCBFids * Fids_Array,
	/*IN */ AFSCBs * CallBacks_Array);

extern int RXAFS_GetVolumeInfo(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * VolumeName,
	/*OUT*/ VolumeInfo * Volumeinfo);

extern afs_int32 SRXAFS_GetVolumeInfo(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * VolumeName,
	/*OUT*/ VolumeInfo * Volumeinfo);

extern int RXAFS_GetVolumeStatus(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 Volumeid,
	/*OUT*/ AFSFetchVolumeStatus * Volumestatus,
	/*OUT*/ char * *Name,
	/*OUT*/ char * *OfflineMsg,
	/*OUT*/ char * *Motd);

extern afs_int32 SRXAFS_GetVolumeStatus(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 Volumeid,
	/*OUT*/ AFSFetchVolumeStatus * Volumestatus,
	/*OUT*/ char * *Name,
	/*OUT*/ char * *OfflineMsg,
	/*OUT*/ char * *Motd);

extern int RXAFS_SetVolumeStatus(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 Volumeid,
	/*IN */ AFSStoreVolumeStatus * Volumestatus,
	/*IN */ char * Name,
	/*IN */ char * OfflineMsg,
	/*IN */ char * Motd);

extern afs_int32 SRXAFS_SetVolumeStatus(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 Volumeid,
	/*IN */ AFSStoreVolumeStatus * Volumestatus,
	/*IN */ char * Name,
	/*IN */ char * OfflineMsg,
	/*IN */ char * Motd);

extern int RXAFS_GetRootVolume(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ char * *VolumeName);

extern afs_int32 SRXAFS_GetRootVolume(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ char * *VolumeName);

extern int RXAFS_CheckToken(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 ViceId,
	/*IN */ AFSOpaque * token);

extern afs_int32 SRXAFS_CheckToken(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 ViceId,
	/*IN */ AFSOpaque * token);

#include <rx/rx_multi.h>
#define multi_RXAFS_GetTime(Seconds, USeconds) \
	multi_Body(StartRXAFS_GetTime(multi_call), EndRXAFS_GetTime(multi_call, Seconds, USeconds))


extern int StartRXAFS_GetTime(
	/*IN */ struct rx_call *z_call);

extern int EndRXAFS_GetTime(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_uint32 * Seconds,
	/*OUT*/ afs_uint32 * USeconds);

extern int RXAFS_GetTime(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ afs_uint32 * Seconds,
	/*OUT*/ afs_uint32 * USeconds);

extern afs_int32 SRXAFS_GetTime(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_uint32 * Seconds,
	/*OUT*/ afs_uint32 * USeconds);

extern int RXAFS_NGetVolumeInfo(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * VolumeName,
	/*OUT*/ AFSVolumeInfo * stuff);

extern afs_int32 SRXAFS_NGetVolumeInfo(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * VolumeName,
	/*OUT*/ AFSVolumeInfo * stuff);

extern int RXAFS_BulkStatus(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSCBFids * FidsArray,
	/*OUT*/ AFSBulkStats * StatArray,
	/*OUT*/ AFSCBs * CBArray,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_BulkStatus(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSCBFids * FidsArray,
	/*OUT*/ AFSBulkStats * StatArray,
	/*OUT*/ AFSCBs * CBArray,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_SetLock(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * Fid,
	/*IN */ ViceLockType Type,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_SetLock(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ ViceLockType Type,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_ExtendLock(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * Fid,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_ExtendLock(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_ReleaseLock(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * Fid,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_ReleaseLock(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_XStatsVersion(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ afs_int32 * versionNumberP);

extern afs_int32 SRXAFS_XStatsVersion(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_int32 * versionNumberP);

extern int RXAFS_GetXStats(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 clientVersionNumber,
	/*IN */ afs_int32 collectionNumber,
	/*OUT*/ afs_int32 * srvVersionNumberP,
	/*OUT*/ afs_int32 * timeP,
	/*OUT*/ AFS_CollData * dataP);

extern afs_int32 SRXAFS_GetXStats(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 clientVersionNumber,
	/*IN */ afs_int32 collectionNumber,
	/*OUT*/ afs_int32 * srvVersionNumberP,
	/*OUT*/ afs_int32 * timeP,
	/*OUT*/ AFS_CollData * dataP);

extern int RXAFS_Lookup(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*OUT*/ AFSFid * OutFid,
	/*OUT*/ AFSFetchStatus * OutFidStatus,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_Lookup(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*OUT*/ AFSFid * OutFid,
	/*OUT*/ AFSFetchStatus * OutFidStatus,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_FlushCPS(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ ViceIds * IdsArray,
	/*IN */ IPAddrs * AddrsArray,
	/*IN */ afs_int32 spare1,
	/*OUT*/ afs_int32 * spare2,
	/*OUT*/ afs_int32 * spare3);

extern afs_int32 SRXAFS_FlushCPS(
	/*IN */ struct rx_call *z_call,
	/*IN */ ViceIds * IdsArray,
	/*IN */ IPAddrs * AddrsArray,
	/*IN */ afs_int32 spare1,
	/*OUT*/ afs_int32 * spare2,
	/*OUT*/ afs_int32 * spare3);

extern int RXAFS_DFSSymlink(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*IN */ char * LinkContents,
	/*IN */ AFSStoreStatus * InStatus,
	/*OUT*/ AFSFid * OutFid,
	/*OUT*/ AFSFetchStatus * OutFidStatus,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_DFSSymlink(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * DirFid,
	/*IN */ char * Name,
	/*IN */ char * LinkContents,
	/*IN */ AFSStoreStatus * InStatus,
	/*OUT*/ AFSFid * OutFid,
	/*OUT*/ AFSFetchStatus * OutFidStatus,
	/*OUT*/ AFSFetchStatus * OutDirStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern int RXAFS_FsCmd(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSFid * Fid,
	/*IN */ struct FsCmdInputs * Inputs,
	/*OUT*/ struct FsCmdOutputs * Outputs);

extern afs_int32 SRXAFS_FsCmd(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ struct FsCmdInputs * Inputs,
	/*OUT*/ struct FsCmdOutputs * Outputs);

extern int RXAFS_InlineBulkStatus(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ AFSCBFids * FidsArray,
	/*OUT*/ AFSBulkStats * StatArray,
	/*OUT*/ AFSCBs * CBArray,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_InlineBulkStatus(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSCBFids * FidsArray,
	/*OUT*/ AFSBulkStats * StatArray,
	/*OUT*/ AFSCBs * CBArray,
	/*OUT*/ AFSVolSync * Sync);

extern int StartRXAFS_FetchData64(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ afs_int64 Pos,
	/*IN */ afs_int64 Length);

extern int EndRXAFS_FetchData64(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_FetchData64(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ afs_int64 Pos,
	/*IN */ afs_int64 Length,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSCallBack * CallBack,
	/*OUT*/ AFSVolSync * Sync);

extern int StartRXAFS_StoreData64(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ AFSStoreStatus * InStatus,
	/*IN */ afs_uint64 Pos,
	/*IN */ afs_uint64 Length,
	/*IN */ afs_uint64 FileLength);

extern int EndRXAFS_StoreData64(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSVolSync * Sync);

extern afs_int32 SRXAFS_StoreData64(
	/*IN */ struct rx_call *z_call,
	/*IN */ AFSFid * Fid,
	/*IN */ AFSStoreStatus * InStatus,
	/*IN */ afs_uint64 Pos,
	/*IN */ afs_uint64 Length,
	/*IN */ afs_uint64 FileLength,
	/*OUT*/ AFSFetchStatus * OutStatus,
	/*OUT*/ AFSVolSync * Sync);

#define multi_RXAFS_GiveUpAllCallBacks() \
	multi_Body(StartRXAFS_GiveUpAllCallBacks(multi_call), EndRXAFS_GiveUpAllCallBacks(multi_call))


extern int StartRXAFS_GiveUpAllCallBacks(
	/*IN */ struct rx_call *z_call);

extern int EndRXAFS_GiveUpAllCallBacks(
	/*IN */ struct rx_call *z_call);

extern int RXAFS_GiveUpAllCallBacks(
	/*IN */ struct rx_connection *z_conn);

extern afs_int32 SRXAFS_GiveUpAllCallBacks(
	/*IN */ struct rx_call *z_call);

#define multi_RXAFS_GetCapabilities(capabilities) \
	multi_Body(StartRXAFS_GetCapabilities(multi_call), EndRXAFS_GetCapabilities(multi_call, capabilities))


extern int StartRXAFS_GetCapabilities(
	/*IN */ struct rx_call *z_call);

extern int EndRXAFS_GetCapabilities(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ Capabilities * capabilities);

extern int RXAFS_GetCapabilities(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ Capabilities * capabilities);

extern afs_int32 SRXAFS_GetCapabilities(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ Capabilities * capabilities);

extern int RXAFS_CallBackRxConnAddr(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 * addr);

extern afs_int32 SRXAFS_CallBackRxConnAddr(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 * addr);
#define STATS64_CURRENTTIME 0
#define STATS64_BOOTTIME 1
#define STATS64_STARTTIME 2
#define STATS64_CURRENTCONNECTIONS 3
#define STATS64_TOTALFETCHES 4
#define STATS64_FETCHDATAS 5
#define STATS64_FETCHEDBYTES 6
#define STATS64_FETCHDATARATE 7
#define STATS64_TOTALSTORES 8
#define STATS64_STOREDATAS 9
#define STATS64_STOREDBYTES 10
#define STATS64_STOREDATARATE 11
#define STATS64_TOTALVICECALLS 12
#define STATS64_WORKSTATIONS 13
#define STATS64_ACTIVEWORKSTATIONS 14
#define STATS64_PROCESSSIZE 15
#define STATS64_VERSION 16

typedef struct ViceStatistics64 {
	u_int ViceStatistics64_len;
	afs_uint64 *ViceStatistics64_val;
} ViceStatistics64;
bool_t xdr_ViceStatistics64(XDR *xdrs, ViceStatistics64 *objp);


extern int RXAFS_GetStatistics64(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 statsVersion,
	/*OUT*/ ViceStatistics64 * Statistics);

extern afs_int32 SRXAFS_GetStatistics64(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 statsVersion,
	/*OUT*/ ViceStatistics64 * Statistics);

extern int RXAFS_ExecuteRequest(struct rx_call *);

/* Opcode-related useful stats for package: RXAFS_ */
#define RXAFS_LOWEST_OPCODE   130
#define RXAFS_HIGHEST_OPCODE	65542
#define RXAFS_NUMBER_OPCODES	42

#define RXAFS_NO_OF_STAT_FUNCS	42

AFS_RXGEN_EXPORT
extern const char *RXAFS_function_names[];

#endif	/* _RXGEN_AFSINT_ */
