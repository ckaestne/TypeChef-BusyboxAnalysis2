/* Machine generated file -- Do NOT edit */

#ifndef	_RXGEN_UBIK_INT_
#define	_RXGEN_UBIK_INT_

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


struct BDesc {
	afs_int32 host;
	short portal;
	afs_int32 session;
};
typedef struct BDesc BDesc;
bool_t xdr_BDesc(XDR *xdrs, BDesc *objp);


struct ubik_version {
	afs_int32 epoch;
	afs_int32 counter;
};
typedef struct ubik_version ubik_version;
bool_t xdr_ubik_version(XDR *xdrs, ubik_version *objp);


struct ubik_tid {
	afs_int32 epoch;
	afs_int32 counter;
};
typedef struct ubik_tid ubik_tid;
bool_t xdr_ubik_tid(XDR *xdrs, ubik_tid *objp);

#define UBIK_MAX_INTERFACE_ADDR 256

struct ubik_debug {
	afs_int32 now;
	afs_int32 lastYesTime;
	afs_int32 lastYesHost;
	afs_int32 lastYesState;
	afs_int32 lastYesClaim;
	afs_int32 lowestHost;
	afs_int32 lowestTime;
	afs_int32 syncHost;
	afs_int32 syncTime;
	struct ubik_version syncVersion;
	struct ubik_tid syncTid;
	afs_int32 amSyncSite;
	afs_int32 syncSiteUntil;
	afs_int32 nServers;
	afs_int32 lockedPages;
	afs_int32 writeLockedPages;
	struct ubik_version localVersion;
	afs_int32 activeWrite;
	afs_int32 tidCounter;
	afs_int32 anyReadLocks;
	afs_int32 anyWriteLocks;
	afs_int32 recoveryState;
	afs_int32 currentTrans;
	afs_int32 writeTrans;
	afs_int32 epochTime;
	afs_int32 interfaceAddr[UBIK_MAX_INTERFACE_ADDR];
};
typedef struct ubik_debug ubik_debug;
bool_t xdr_ubik_debug(XDR *xdrs, ubik_debug *objp);


struct ubik_sdebug {
	afs_int32 addr;
	afs_int32 lastVoteTime;
	afs_int32 lastBeaconSent;
	afs_int32 lastVote;
	struct ubik_version remoteVersion;
	afs_int32 currentDB;
	afs_int32 beaconSinceDown;
	afs_int32 up;
	afs_int32 altAddr[255];
};
typedef struct ubik_sdebug ubik_sdebug;
bool_t xdr_ubik_sdebug(XDR *xdrs, ubik_sdebug *objp);


struct ubik_debug_old {
	afs_int32 now;
	afs_int32 lastYesTime;
	afs_int32 lastYesHost;
	afs_int32 lastYesState;
	afs_int32 lastYesClaim;
	afs_int32 lowestHost;
	afs_int32 lowestTime;
	afs_int32 syncHost;
	afs_int32 syncTime;
	struct ubik_version syncVersion;
	struct ubik_tid syncTid;
	afs_int32 amSyncSite;
	afs_int32 syncSiteUntil;
	afs_int32 nServers;
	afs_int32 lockedPages;
	afs_int32 writeLockedPages;
	struct ubik_version localVersion;
	afs_int32 activeWrite;
	afs_int32 tidCounter;
	afs_int32 anyReadLocks;
	afs_int32 anyWriteLocks;
	afs_int32 recoveryState;
	afs_int32 currentTrans;
	afs_int32 writeTrans;
	afs_int32 epochTime;
};
typedef struct ubik_debug_old ubik_debug_old;
bool_t xdr_ubik_debug_old(XDR *xdrs, ubik_debug_old *objp);


struct ubik_sdebug_old {
	afs_int32 addr;
	afs_int32 lastVoteTime;
	afs_int32 lastBeaconSent;
	afs_int32 lastVote;
	struct ubik_version remoteVersion;
	afs_int32 currentDB;
	afs_int32 beaconSinceDown;
	afs_int32 up;
};
typedef struct ubik_sdebug_old ubik_sdebug_old;
bool_t xdr_ubik_sdebug_old(XDR *xdrs, ubik_sdebug_old *objp);


struct UbikInterfaceAddr {
	afs_int32 hostAddr[UBIK_MAX_INTERFACE_ADDR];
};
typedef struct UbikInterfaceAddr UbikInterfaceAddr;
bool_t xdr_UbikInterfaceAddr(XDR *xdrs, UbikInterfaceAddr *objp);

#define BULK_ERROR 1

typedef struct bulkdata {
	u_int bulkdata_len;
	char *bulkdata_val;
} bulkdata;
bool_t xdr_bulkdata(XDR *xdrs, bulkdata *objp);

#define IOVEC_MAXBUF 65536
#define IOVEC_MAXWRT 64

typedef struct iovec_buf {
	u_int iovec_buf_len;
	char *iovec_buf_val;
} iovec_buf;
bool_t xdr_iovec_buf(XDR *xdrs, iovec_buf *objp);


struct ubik_iovec {
	afs_int32 file;
	afs_int32 position;
	afs_int32 length;
};
typedef struct ubik_iovec ubik_iovec;
bool_t xdr_ubik_iovec(XDR *xdrs, ubik_iovec *objp);


typedef struct iovec_wrt {
	u_int iovec_wrt_len;
	ubik_iovec *iovec_wrt_val;
} iovec_wrt;
bool_t xdr_iovec_wrt(XDR *xdrs, iovec_wrt *objp);

#define VOTE_STATINDEX 11

#include <rx/rx_multi.h>
#define multi_VOTE_Beacon(state, voteStart, Version, tid) \
	multi_Body(StartVOTE_Beacon(multi_call, state, voteStart, Version, tid), EndVOTE_Beacon(multi_call))


extern int StartVOTE_Beacon(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 state,
	/*IN */ afs_int32 voteStart,
	/*IN */ ubik_version * Version,
	/*IN */ ubik_tid * tid);

extern int EndVOTE_Beacon(
	/*IN */ struct rx_call *z_call);

extern int VOTE_Beacon(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 state,
	/*IN */ afs_int32 voteStart,
	/*IN */ ubik_version * Version,
	/*IN */ ubik_tid * tid);

extern afs_int32 SVOTE_Beacon(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 state,
	/*IN */ afs_int32 voteStart,
	/*IN */ ubik_version * Version,
	/*IN */ ubik_tid * tid);

extern int VOTE_DebugOld(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ ubik_debug_old * db);

extern afs_int32 SVOTE_DebugOld(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ ubik_debug_old * db);

extern int VOTE_SDebugOld(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 which,
	/*OUT*/ ubik_sdebug_old * db);

extern afs_int32 SVOTE_SDebugOld(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 which,
	/*OUT*/ ubik_sdebug_old * db);

extern int VOTE_GetSyncSite(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 * site);

extern afs_int32 SVOTE_GetSyncSite(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 * site);

extern int VOTE_Debug(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ ubik_debug * db);

extern afs_int32 SVOTE_Debug(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ ubik_debug * db);

extern int VOTE_SDebug(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 which,
	/*OUT*/ ubik_sdebug * db);

extern afs_int32 SVOTE_SDebug(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 which,
	/*OUT*/ ubik_sdebug * db);

extern int VOTE_XDebug(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ ubik_debug * db,
	/*OUT*/ afs_int32 * isClone);

extern afs_int32 SVOTE_XDebug(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ ubik_debug * db,
	/*OUT*/ afs_int32 * isClone);

extern int VOTE_XSDebug(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 which,
	/*OUT*/ ubik_sdebug * db,
	/*OUT*/ afs_int32 * isClone);

extern afs_int32 SVOTE_XSDebug(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 which,
	/*OUT*/ ubik_sdebug * db,
	/*OUT*/ afs_int32 * isClone);
#define DISK_STATINDEX 12

extern int DISK_Begin(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ ubik_tid * tid);

extern afs_int32 SDISK_Begin(
	/*IN */ struct rx_call *z_call,
	/*IN */ ubik_tid * tid);

extern int DISK_Commit(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ ubik_tid * tid);

extern afs_int32 SDISK_Commit(
	/*IN */ struct rx_call *z_call,
	/*IN */ ubik_tid * tid);

extern int DISK_Lock(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ ubik_tid * tid,
	/*IN */ afs_int32 file,
	/*IN */ afs_int32 position,
	/*IN */ afs_int32 length,
	/*IN */ afs_int32 type);

extern afs_int32 SDISK_Lock(
	/*IN */ struct rx_call *z_call,
	/*IN */ ubik_tid * tid,
	/*IN */ afs_int32 file,
	/*IN */ afs_int32 position,
	/*IN */ afs_int32 length,
	/*IN */ afs_int32 type);

extern int DISK_Write(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ ubik_tid * tid,
	/*IN */ afs_int32 file,
	/*IN */ afs_int32 position,
	/*IN */ bulkdata * data);

extern afs_int32 SDISK_Write(
	/*IN */ struct rx_call *z_call,
	/*IN */ ubik_tid * tid,
	/*IN */ afs_int32 file,
	/*IN */ afs_int32 position,
	/*IN */ bulkdata * data);

extern int DISK_GetVersion(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ ubik_version * Version);

extern afs_int32 SDISK_GetVersion(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ ubik_version * Version);

extern int StartDISK_GetFile(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 file);

extern int EndDISK_GetFile(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ ubik_version * Version);

extern afs_int32 SDISK_GetFile(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 file,
	/*OUT*/ ubik_version * Version);

extern int StartDISK_SendFile(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 file,
	/*IN */ afs_int32 length,
	/*IN */ ubik_version * Version);

extern int EndDISK_SendFile(
	/*IN */ struct rx_call *z_call);

extern afs_int32 SDISK_SendFile(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 file,
	/*IN */ afs_int32 length,
	/*IN */ ubik_version * Version);

extern int DISK_Abort(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ ubik_tid * tid);

extern afs_int32 SDISK_Abort(
	/*IN */ struct rx_call *z_call,
	/*IN */ ubik_tid * tid);

extern int DISK_ReleaseLocks(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ ubik_tid * tid);

extern afs_int32 SDISK_ReleaseLocks(
	/*IN */ struct rx_call *z_call,
	/*IN */ ubik_tid * tid);

extern int DISK_Truncate(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ ubik_tid * tid,
	/*IN */ afs_int32 file,
	/*IN */ afs_int32 length);

extern afs_int32 SDISK_Truncate(
	/*IN */ struct rx_call *z_call,
	/*IN */ ubik_tid * tid,
	/*IN */ afs_int32 file,
	/*IN */ afs_int32 length);

#define multi_DISK_Probe() \
	multi_Body(StartDISK_Probe(multi_call), EndDISK_Probe(multi_call))


extern int StartDISK_Probe(
	/*IN */ struct rx_call *z_call);

extern int EndDISK_Probe(
	/*IN */ struct rx_call *z_call);

extern int DISK_Probe(
	/*IN */ struct rx_connection *z_conn);

extern afs_int32 SDISK_Probe(
	/*IN */ struct rx_call *z_call);

extern int DISK_WriteV(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ ubik_tid * tid,
	/*IN */ iovec_wrt * io_vector,
	/*IN */ iovec_buf * io_buffer);

extern afs_int32 SDISK_WriteV(
	/*IN */ struct rx_call *z_call,
	/*IN */ ubik_tid * tid,
	/*IN */ iovec_wrt * io_vector,
	/*IN */ iovec_buf * io_buffer);

#define multi_DISK_UpdateInterfaceAddr(inAddr, outAddr) \
	multi_Body(StartDISK_UpdateInterfaceAddr(multi_call, inAddr), EndDISK_UpdateInterfaceAddr(multi_call, outAddr))


extern int StartDISK_UpdateInterfaceAddr(
	/*IN */ struct rx_call *z_call,
	/*IN */ UbikInterfaceAddr * inAddr);

extern int EndDISK_UpdateInterfaceAddr(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ UbikInterfaceAddr * outAddr);

extern int DISK_UpdateInterfaceAddr(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ UbikInterfaceAddr * inAddr,
	/*OUT*/ UbikInterfaceAddr * outAddr);

extern afs_int32 SDISK_UpdateInterfaceAddr(
	/*IN */ struct rx_call *z_call,
	/*IN */ UbikInterfaceAddr * inAddr,
	/*OUT*/ UbikInterfaceAddr * outAddr);

extern int DISK_SetVersion(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ ubik_tid * tid,
	/*IN */ ubik_version * OldVersion,
	/*IN */ ubik_version * NewVersion);

extern afs_int32 SDISK_SetVersion(
	/*IN */ struct rx_call *z_call,
	/*IN */ ubik_tid * tid,
	/*IN */ ubik_version * OldVersion,
	/*IN */ ubik_version * NewVersion);

extern int VOTE_ExecuteRequest(struct rx_call *);

extern int DISK_ExecuteRequest(struct rx_call *);

/* Opcode-related useful stats for package: VOTE_ */
#define VOTE_LOWEST_OPCODE   10000
#define VOTE_HIGHEST_OPCODE	10007
#define VOTE_NUMBER_OPCODES	8

#define VOTE_NO_OF_STAT_FUNCS	8

AFS_RXGEN_EXPORT
extern const char *VOTE_function_names[];


/* Opcode-related useful stats for package: DISK_ */
#define DISK_LOWEST_OPCODE   20000
#define DISK_HIGHEST_OPCODE	20013
#define DISK_NUMBER_OPCODES	14

#define DISK_NO_OF_STAT_FUNCS	14

AFS_RXGEN_EXPORT
extern const char *DISK_function_names[];

#endif	/* _RXGEN_UBIK_INT_ */
