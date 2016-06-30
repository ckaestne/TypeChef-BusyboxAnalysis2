/* Machine generated file -- Do NOT edit */

#ifndef	_RXGEN_BUMON_
#define	_RXGEN_BUMON_

#ifdef	KERNEL
/* The following 'ifndefs' are not a good solution to the vendor's omission of surrounding all system includes with 'ifndef's since it requires that this file is included after the system includes...*/
#include <afsconfig.h>
#include "afs/param.h"
#ifdef	UKERNEL
#include "afs/sysincludes.h"
#include "rx/xdr.h"
#include "rx/rx.h"
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
#else	/* KERNEL */
#include <afs/param.h>
#include <afs/stds.h>
#include <sys/types.h>
#include <rx/xdr.h>
#include <rx/rx.h>
#include <afs/rxgen_consts.h>
#endif	/* KERNEL */

#ifdef AFS_NT40_ENV
#ifndef AFS_RXGEN_EXPORT
#define AFS_RXGEN_EXPORT __declspec(dllimport)
#endif /* AFS_RXGEN_EXPORT */
#else /* AFS_NT40_ENV */
#define AFS_RXGEN_EXPORT
#endif /* AFS_NT40_ENV */

#define BC_STATINDEX 3

struct bc_junk {
	afs_int32 a;
};
typedef struct bc_junk bc_junk;
bool_t xdr_bc_junk(XDR *xdrs, bc_junk *objp);


extern int BC_Print(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 code,
	/*IN */ afs_int32 flags,
	/*IN */ char * message);

extern afs_int32 SBC_Print(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 code,
	/*IN */ afs_int32 flags,
	/*IN */ char * message);

extern int BC_ExecuteRequest(struct rx_call *);

/* Opcode-related useful stats for package: BC_ */
#define BC_LOWEST_OPCODE   100
#define BC_HIGHEST_OPCODE	100
#define BC_NUMBER_OPCODES	1

#endif	/* _RXGEN_BUMON_ */
