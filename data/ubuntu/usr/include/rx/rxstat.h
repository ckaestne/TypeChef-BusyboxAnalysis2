/* Machine generated file -- Do NOT edit */

#ifndef	_RXGEN_RXSTAT_
#define	_RXGEN_RXSTAT_

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


typedef struct rpcStats {
	u_int rpcStats_len;
	afs_uint32 *rpcStats_val;
} rpcStats;
bool_t xdr_rpcStats(XDR *xdrs, rpcStats *objp);

#define RXSTATS_STATINDEX 9

#include <rx/rx_multi.h>
#define multi_RXSTATS_RetrieveProcessRPCStats(clientVersion, serverVersion, clock_sec, clock_usec, stat_count, stats) \
	multi_Body(StartRXSTATS_RetrieveProcessRPCStats(multi_call, clientVersion), EndRXSTATS_RetrieveProcessRPCStats(multi_call, serverVersion, clock_sec, clock_usec, stat_count, stats))


extern int StartRXSTATS_RetrieveProcessRPCStats(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 clientVersion);

extern int EndRXSTATS_RetrieveProcessRPCStats(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_uint32 * serverVersion,
	/*OUT*/ afs_uint32 * clock_sec,
	/*OUT*/ afs_uint32 * clock_usec,
	/*OUT*/ afs_uint32 * stat_count,
	/*OUT*/ rpcStats * stats);

extern int RXSTATS_RetrieveProcessRPCStats(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 clientVersion,
	/*OUT*/ afs_uint32 * serverVersion,
	/*OUT*/ afs_uint32 * clock_sec,
	/*OUT*/ afs_uint32 * clock_usec,
	/*OUT*/ afs_uint32 * stat_count,
	/*OUT*/ rpcStats * stats);

extern afs_int32 MRXSTATS_RetrieveProcessRPCStats(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 clientVersion,
	/*OUT*/ afs_uint32 * serverVersion,
	/*OUT*/ afs_uint32 * clock_sec,
	/*OUT*/ afs_uint32 * clock_usec,
	/*OUT*/ afs_uint32 * stat_count,
	/*OUT*/ rpcStats * stats);

#define multi_RXSTATS_RetrievePeerRPCStats(clientVersion, serverVersion, stat_count, clock_sec, clock_usec, stats) \
	multi_Body(StartRXSTATS_RetrievePeerRPCStats(multi_call, clientVersion), EndRXSTATS_RetrievePeerRPCStats(multi_call, serverVersion, stat_count, clock_sec, clock_usec, stats))


extern int StartRXSTATS_RetrievePeerRPCStats(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 clientVersion);

extern int EndRXSTATS_RetrievePeerRPCStats(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_uint32 * serverVersion,
	/*OUT*/ afs_uint32 * stat_count,
	/*OUT*/ afs_uint32 * clock_sec,
	/*OUT*/ afs_uint32 * clock_usec,
	/*OUT*/ rpcStats * stats);

extern int RXSTATS_RetrievePeerRPCStats(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 clientVersion,
	/*OUT*/ afs_uint32 * serverVersion,
	/*OUT*/ afs_uint32 * stat_count,
	/*OUT*/ afs_uint32 * clock_sec,
	/*OUT*/ afs_uint32 * clock_usec,
	/*OUT*/ rpcStats * stats);

extern afs_int32 MRXSTATS_RetrievePeerRPCStats(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 clientVersion,
	/*OUT*/ afs_uint32 * serverVersion,
	/*OUT*/ afs_uint32 * stat_count,
	/*OUT*/ afs_uint32 * clock_sec,
	/*OUT*/ afs_uint32 * clock_usec,
	/*OUT*/ rpcStats * stats);

extern int RXSTATS_QueryProcessRPCStats(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ afs_int32 * on);

extern afs_int32 MRXSTATS_QueryProcessRPCStats(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_int32 * on);

extern int RXSTATS_QueryPeerRPCStats(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ afs_int32 * on);

extern afs_int32 MRXSTATS_QueryPeerRPCStats(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_int32 * on);

extern int RXSTATS_EnableProcessRPCStats(
	/*IN */ struct rx_connection *z_conn);

extern afs_int32 MRXSTATS_EnableProcessRPCStats(
	/*IN */ struct rx_call *z_call);

extern int RXSTATS_EnablePeerRPCStats(
	/*IN */ struct rx_connection *z_conn);

extern afs_int32 MRXSTATS_EnablePeerRPCStats(
	/*IN */ struct rx_call *z_call);

extern int RXSTATS_DisableProcessRPCStats(
	/*IN */ struct rx_connection *z_conn);

extern afs_int32 MRXSTATS_DisableProcessRPCStats(
	/*IN */ struct rx_call *z_call);

extern int RXSTATS_DisablePeerRPCStats(
	/*IN */ struct rx_connection *z_conn);

extern afs_int32 MRXSTATS_DisablePeerRPCStats(
	/*IN */ struct rx_call *z_call);

extern int RXSTATS_QueryRPCStatsVersion(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ afs_uint32 * ver);

extern afs_int32 MRXSTATS_QueryRPCStatsVersion(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_uint32 * ver);

extern int RXSTATS_ClearProcessRPCStats(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 clearFlag);

extern afs_int32 MRXSTATS_ClearProcessRPCStats(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 clearFlag);

extern int RXSTATS_ClearPeerRPCStats(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 clearFlag);

extern afs_int32 MRXSTATS_ClearPeerRPCStats(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 clearFlag);

extern int RXSTATS_ExecuteRequest(struct rx_call *);

/* Opcode-related useful stats for package: RXSTATS_ */
#define RXSTATS_LOWEST_OPCODE   0
#define RXSTATS_HIGHEST_OPCODE	10
#define RXSTATS_NUMBER_OPCODES	11

#define RXSTATS_NO_OF_STAT_FUNCS	11

AFS_RXGEN_EXPORT
extern const char *RXSTATS_function_names[];

#endif	/* _RXGEN_RXSTAT_ */
