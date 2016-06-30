/* Machine generated file -- Do NOT edit */

#ifndef	_RXGEN_VOLINT_
#define	_RXGEN_VOLINT_

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

#define AFSVolSTATINDEX 16
#define VOLDUMPV2_OMITDIRS 1
#define SIZE 1024

struct volser_status {
	afs_uint32 volID;
	afs_int32 nextUnique;
	int type;
	afs_uint32 parentID;
	afs_uint32 cloneID;
	afs_uint32 backupID;
	afs_uint32 restoredFromID;
	afs_int32 maxQuota;
	afs_int32 minQuota;
	afs_int32 owner;
	afs_int32 creationDate;
	afs_int32 accessDate;
	afs_int32 updateDate;
	afs_int32 expirationDate;
	afs_int32 backupDate;
	afs_int32 copyDate;
};
typedef struct volser_status volser_status;
bool_t xdr_volser_status(XDR *xdrs, volser_status *objp);


struct destServer {
	afs_int32 destHost;
	afs_int32 destPort;
	afs_int32 destSSID;
};
typedef struct destServer destServer;
bool_t xdr_destServer(XDR *xdrs, destServer *objp);


struct volintInfo {
	char name[32];
	afs_uint32 volid;
	afs_int32 type;
	afs_uint32 backupID;
	afs_uint32 parentID;
	afs_uint32 cloneID;
	afs_int32 status;
	afs_int32 copyDate;
	u_char inUse;
	u_char needsSalvaged;
	u_char destroyMe;
	afs_int32 creationDate;
	afs_int32 accessDate;
	afs_int32 updateDate;
	afs_int32 backupDate;
	int dayUse;
	int filecount;
	int maxquota;
	int size;
	afs_int32 flags;
	afs_int32 spare0;
	afs_int32 spare1;
	afs_int32 spare2;
	afs_int32 spare3;
};
typedef struct volintInfo volintInfo;
bool_t xdr_volintInfo(XDR *xdrs, volintInfo *objp);

#define VOLINT_STATS_NUM_RWINFO_FIELDS 4
#define VOLINT_STATS_SAME_NET 0
#define VOLINT_STATS_SAME_NET_AUTH 1
#define VOLINT_STATS_DIFF_NET 2
#define VOLINT_STATS_DIFF_NET_AUTH 3
#define VOLINT_STATS_NUM_TIME_RANGES 6
#define VOLINT_STATS_TIME_CAP_0 60
#define VOLINT_STATS_TIME_CAP_1 600
#define VOLINT_STATS_TIME_CAP_2 3600
#define VOLINT_STATS_TIME_CAP_3 86400
#define VOLINT_STATS_TIME_CAP_4 604800
#define VOLINT_STATS_NUM_TIME_FIELDS 6
#define VOLINT_STATS_TIME_IDX_0 0
#define VOLINT_STATS_TIME_IDX_1 1
#define VOLINT_STATS_TIME_IDX_2 2
#define VOLINT_STATS_TIME_IDX_3 3
#define VOLINT_STATS_TIME_IDX_4 4
#define VOLINT_STATS_TIME_IDX_5 5

struct volintXInfo {
	char name[32];
	afs_uint32 volid;
	afs_int32 type;
	afs_uint32 backupID;
	afs_uint32 parentID;
	afs_uint32 cloneID;
	afs_int32 status;
	afs_int32 copyDate;
	u_char inUse;
	afs_int32 creationDate;
	afs_int32 accessDate;
	afs_int32 updateDate;
	afs_int32 backupDate;
	int dayUse;
	int filecount;
	int maxquota;
	int size;
	afs_int32 stat_reads[VOLINT_STATS_NUM_RWINFO_FIELDS];
	afs_int32 stat_writes[VOLINT_STATS_NUM_RWINFO_FIELDS];
	afs_int32 stat_fileSameAuthor[VOLINT_STATS_NUM_TIME_FIELDS];
	afs_int32 stat_fileDiffAuthor[VOLINT_STATS_NUM_TIME_FIELDS];
	afs_int32 stat_dirSameAuthor[VOLINT_STATS_NUM_TIME_FIELDS];
	afs_int32 stat_dirDiffAuthor[VOLINT_STATS_NUM_TIME_FIELDS];
};
typedef struct volintXInfo volintXInfo;
bool_t xdr_volintXInfo(XDR *xdrs, volintXInfo *objp);


struct transDebugInfo {
	afs_int32 tid;
	afs_int32 time;
	afs_int32 creationTime;
	afs_int32 returnCode;
	afs_uint32 volid;
	afs_int32 partition;
	short iflags;
	char vflags;
	char tflags;
	char lastProcName[30];
	int callValid;
	afs_int32 readNext;
	afs_int32 transmitNext;
	int lastSendTime;
	int lastReceiveTime;
};
typedef struct transDebugInfo transDebugInfo;
bool_t xdr_transDebugInfo(XDR *xdrs, transDebugInfo *objp);


struct pIDs {
	afs_int32 partIds[26];
};
typedef struct pIDs pIDs;
bool_t xdr_pIDs(XDR *xdrs, pIDs *objp);


struct diskPartition {
	char name[32];
	char devName[32];
	int lock_fd;
	int totalUsable;
	int free;
	int minFree;
};
typedef struct diskPartition diskPartition;
bool_t xdr_diskPartition(XDR *xdrs, diskPartition *objp);


struct diskPartition64 {
	char name[256];
	char devName[256];
	int lock_fd;
	afs_int64 totalUsable;
	afs_int64 free;
	afs_int64 minFree;
};
typedef struct diskPartition64 diskPartition64;
bool_t xdr_diskPartition64(XDR *xdrs, diskPartition64 *objp);


struct restoreCookie {
	char name[32];
	afs_int32 type;
	afs_uint32 clone;
	afs_uint32 parent;
};
typedef struct restoreCookie restoreCookie;
bool_t xdr_restoreCookie(XDR *xdrs, restoreCookie *objp);


struct replica {
	afs_int32 trans;
	struct destServer server;
};
typedef struct replica replica;
bool_t xdr_replica(XDR *xdrs, replica *objp);


struct volintSize {
	afs_uint64 dump_size;
};
typedef struct volintSize volintSize;
bool_t xdr_volintSize(XDR *xdrs, volintSize *objp);


typedef struct manyDests {
	u_int manyDests_len;
	replica *manyDests_val;
} manyDests;
bool_t xdr_manyDests(XDR *xdrs, manyDests *objp);


typedef struct manyResults {
	u_int manyResults_len;
	afs_int32 *manyResults_val;
} manyResults;
bool_t xdr_manyResults(XDR *xdrs, manyResults *objp);


typedef struct transDebugEntries {
	u_int transDebugEntries_len;
	transDebugInfo *transDebugEntries_val;
} transDebugEntries;
bool_t xdr_transDebugEntries(XDR *xdrs, transDebugEntries *objp);


typedef struct volEntries {
	u_int volEntries_len;
	volintInfo *volEntries_val;
} volEntries;
bool_t xdr_volEntries(XDR *xdrs, volEntries *objp);


typedef struct partEntries {
	u_int partEntries_len;
	afs_int32 *partEntries_val;
} partEntries;
bool_t xdr_partEntries(XDR *xdrs, partEntries *objp);


typedef struct volXEntries {
	u_int volXEntries_len;
	volintXInfo *volXEntries_val;
} volXEntries;
bool_t xdr_volXEntries(XDR *xdrs, volXEntries *objp);


extern int AFSVolCreateVolume(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 partition,
	/*IN */ char * name,
	/*IN */ afs_int32 type,
	/*IN */ afs_uint32 parent,
	/*I/O*/ afs_uint32 * volid,
	/*OUT*/ afs_int32 * trans);

extern afs_int32 SAFSVolCreateVolume(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 partition,
	/*IN */ char * name,
	/*IN */ afs_int32 type,
	/*IN */ afs_uint32 parent,
	/*I/O*/ afs_uint32 * volid,
	/*OUT*/ afs_int32 * trans);

extern int AFSVolDeleteVolume(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 trans);

extern afs_int32 SAFSVolDeleteVolume(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 trans);

extern int StartAFSVolRestore(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 toTrans,
	/*IN */ afs_int32 flags,
	/*IN */ struct restoreCookie * cookie);

extern int EndAFSVolRestore(
	/*IN */ struct rx_call *z_call);

extern afs_int32 SAFSVolRestore(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 toTrans,
	/*IN */ afs_int32 flags,
	/*IN */ struct restoreCookie * cookie);

extern int AFSVolForward(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 fromTrans,
	/*IN */ afs_int32 fromDate,
	/*IN */ struct destServer * destination,
	/*IN */ afs_int32 destTrans,
	/*IN */ struct restoreCookie * cookie);

extern afs_int32 SAFSVolForward(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 fromTrans,
	/*IN */ afs_int32 fromDate,
	/*IN */ struct destServer * destination,
	/*IN */ afs_int32 destTrans,
	/*IN */ struct restoreCookie * cookie);

extern int AFSVolEndTrans(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 trans,
	/*OUT*/ afs_int32 * rcode);

extern afs_int32 SAFSVolEndTrans(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 trans,
	/*OUT*/ afs_int32 * rcode);

extern int AFSVolClone(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 trans,
	/*IN */ afs_uint32 purgeVol,
	/*IN */ afs_int32 newType,
	/*IN */ char * newName,
	/*I/O*/ afs_uint32 * newVol);

extern afs_int32 SAFSVolClone(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 trans,
	/*IN */ afs_uint32 purgeVol,
	/*IN */ afs_int32 newType,
	/*IN */ char * newName,
	/*I/O*/ afs_uint32 * newVol);

extern int AFSVolSetFlags(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 trans,
	/*IN */ afs_int32 flags);

extern afs_int32 SAFSVolSetFlags(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 trans,
	/*IN */ afs_int32 flags);

extern int AFSVolGetFlags(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 trans,
	/*OUT*/ afs_int32 * flags);

extern afs_int32 SAFSVolGetFlags(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 trans,
	/*OUT*/ afs_int32 * flags);

extern int AFSVolTransCreate(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 volume,
	/*IN */ afs_int32 partition,
	/*IN */ afs_int32 flags,
	/*OUT*/ afs_int32 * trans);

extern afs_int32 SAFSVolTransCreate(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 volume,
	/*IN */ afs_int32 partition,
	/*IN */ afs_int32 flags,
	/*OUT*/ afs_int32 * trans);

extern int StartAFSVolDump(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 fromTrans,
	/*IN */ afs_int32 fromDate);

extern int EndAFSVolDump(
	/*IN */ struct rx_call *z_call);

extern afs_int32 SAFSVolDump(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 fromTrans,
	/*IN */ afs_int32 fromDate);

extern int AFSVolGetNthVolume(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 index,
	/*OUT*/ afs_uint32 * volume,
	/*OUT*/ afs_int32 * partition);

extern afs_int32 SAFSVolGetNthVolume(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 index,
	/*OUT*/ afs_uint32 * volume,
	/*OUT*/ afs_int32 * partition);

extern int AFSVolSetForwarding(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 tid,
	/*IN */ afs_int32 newsite);

extern afs_int32 SAFSVolSetForwarding(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 tid,
	/*IN */ afs_int32 newsite);

extern int AFSVolGetName(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 tid,
	/*OUT*/ char * *tname);

extern afs_int32 SAFSVolGetName(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 tid,
	/*OUT*/ char * *tname);

extern int AFSVolGetStatus(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 tid,
	/*OUT*/ struct volser_status * status);

extern afs_int32 SAFSVolGetStatus(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 tid,
	/*OUT*/ struct volser_status * status);

extern int AFSVolSignalRestore(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * name,
	/*IN */ int type,
	/*IN */ afs_uint32 pid,
	/*IN */ afs_uint32 cloneid);

extern afs_int32 SAFSVolSignalRestore(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * name,
	/*IN */ int type,
	/*IN */ afs_uint32 pid,
	/*IN */ afs_uint32 cloneid);

extern int AFSVolListPartitions(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ struct pIDs * partIDs);

extern afs_int32 SAFSVolListPartitions(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ struct pIDs * partIDs);

extern int AFSVolListVolumes(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 partID,
	/*IN */ afs_int32 flags,
	/*OUT*/ volEntries * resultEntries);

extern afs_int32 SAFSVolListVolumes(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 partID,
	/*IN */ afs_int32 flags,
	/*OUT*/ volEntries * resultEntries);

extern int AFSVolSetIdsTypes(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 tId,
	/*IN */ char * name,
	/*IN */ afs_int32 type,
	/*IN */ afs_uint32 pId,
	/*IN */ afs_uint32 cloneId,
	/*IN */ afs_uint32 backupId);

extern afs_int32 SAFSVolSetIdsTypes(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 tId,
	/*IN */ char * name,
	/*IN */ afs_int32 type,
	/*IN */ afs_uint32 pId,
	/*IN */ afs_uint32 cloneId,
	/*IN */ afs_uint32 backupId);

extern int AFSVolMonitor(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ transDebugEntries * result);

extern afs_int32 SAFSVolMonitor(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ transDebugEntries * result);

extern int AFSVolPartitionInfo(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * name,
	/*OUT*/ struct diskPartition * partition);

extern afs_int32 SAFSVolPartitionInfo(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * name,
	/*OUT*/ struct diskPartition * partition);

extern int AFSVolReClone(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 tid,
	/*IN */ afs_uint32 cloneID);

extern afs_int32 SAFSVolReClone(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 tid,
	/*IN */ afs_uint32 cloneID);

extern int AFSVolListOneVolume(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 partID,
	/*IN */ afs_uint32 volid,
	/*OUT*/ volEntries * resultEntries);

extern afs_int32 SAFSVolListOneVolume(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 partID,
	/*IN */ afs_uint32 volid,
	/*OUT*/ volEntries * resultEntries);

extern int AFSVolNukeVolume(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 partID,
	/*IN */ afs_uint32 volID);

extern afs_int32 SAFSVolNukeVolume(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 partID,
	/*IN */ afs_uint32 volID);

extern int AFSVolSetDate(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 tid,
	/*IN */ afs_int32 newDate);

extern afs_int32 SAFSVolSetDate(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 tid,
	/*IN */ afs_int32 newDate);

extern int AFSVolXListVolumes(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 partID,
	/*IN */ afs_int32 flags,
	/*OUT*/ volXEntries * resultXEntriesP);

extern afs_int32 SAFSVolXListVolumes(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 partID,
	/*IN */ afs_int32 flags,
	/*OUT*/ volXEntries * resultXEntriesP);

extern int AFSVolXListOneVolume(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 partID,
	/*IN */ afs_uint32 volid,
	/*OUT*/ volXEntries * resultXEntries);

extern afs_int32 SAFSVolXListOneVolume(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 partID,
	/*IN */ afs_uint32 volid,
	/*OUT*/ volXEntries * resultXEntries);

extern int AFSVolSetInfo(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 tid,
	/*IN */ struct volintInfo * status);

extern afs_int32 SAFSVolSetInfo(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 tid,
	/*IN */ struct volintInfo * status);

extern int AFSVolXListPartitions(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ struct partEntries * partIDs);

extern afs_int32 SAFSVolXListPartitions(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ struct partEntries * partIDs);

extern int AFSVolForwardMultiple(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 fromTrans,
	/*IN */ afs_int32 fromDate,
	/*IN */ manyDests * destinations,
	/*IN */ afs_int32 spare,
	/*IN */ struct restoreCookie * cookie,
	/*OUT*/ manyResults * results);

extern afs_int32 SAFSVolForwardMultiple(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 fromTrans,
	/*IN */ afs_int32 fromDate,
	/*IN */ manyDests * destinations,
	/*IN */ afs_int32 spare,
	/*IN */ struct restoreCookie * cookie,
	/*OUT*/ manyResults * results);

extern int AFSVolConvertROtoRWvolume(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 partid,
	/*IN */ afs_uint32 volid);

extern afs_int32 SAFSVolConvertROtoRWvolume(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 partid,
	/*IN */ afs_uint32 volid);

extern int AFSVolGetSize(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 fromTrans,
	/*IN */ afs_int32 fromDate,
	/*OUT*/ struct volintSize * size);

extern afs_int32 SAFSVolGetSize(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 fromTrans,
	/*IN */ afs_int32 fromDate,
	/*OUT*/ struct volintSize * size);

extern int StartAFSVolDumpV2(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 fromTrans,
	/*IN */ afs_int32 fromDate,
	/*IN */ afs_int32 flags);

extern int EndAFSVolDumpV2(
	/*IN */ struct rx_call *z_call);

extern afs_int32 SAFSVolDumpV2(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 fromTrans,
	/*IN */ afs_int32 fromDate,
	/*IN */ afs_int32 flags);

extern int AFSVolPartitionInfo64(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * name,
	/*OUT*/ struct diskPartition64 * partition);

extern afs_int32 SAFSVolPartitionInfo64(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * name,
	/*OUT*/ struct diskPartition64 * partition);

extern int StartAFSVolSplitVolume(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 vid,
	/*IN */ afs_uint32 newid,
	/*IN */ afs_uint32 where,
	/*IN */ afs_int32 verbose);

extern int EndAFSVolSplitVolume(
	/*IN */ struct rx_call *z_call);

extern afs_int32 SAFSVolSplitVolume(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 vid,
	/*IN */ afs_uint32 newid,
	/*IN */ afs_uint32 where,
	/*IN */ afs_int32 verbose);

extern int AFSVolExecuteRequest(struct rx_call *);

/* Opcode-related useful stats for package: AFSVol */
#define AFSVolLOWEST_OPCODE   100
#define AFSVolHIGHEST_OPCODE	65547
#define AFSVolNUMBER_OPCODES	34

#define AFSVolNO_OF_STAT_FUNCS	34

AFS_RXGEN_EXPORT
extern const char *AFSVolfunction_names[];

#endif	/* _RXGEN_VOLINT_ */
