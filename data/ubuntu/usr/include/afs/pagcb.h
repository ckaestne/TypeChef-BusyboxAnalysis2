/* Machine generated file -- Do NOT edit */

#ifndef	_RXGEN_PAGCB_
#define	_RXGEN_PAGCB_

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

#define PAGCB_STATINDEX 21
#define PAGCB_SERVICEID 2
#define PAGCB_MAXREALMLEN 256
#define PAGCB_MAXTICKETLEN 12000
#define PAGCB_MAXCREDS 256
#define PAGCB_MAXSYSNAMELEN 128
#define PAGCB_MAXSYSNAMES 16

struct PAGCB_ClearToken {
	afs_int32 AuthHandle;
	char HandShakeKey[8];
	afs_int32 ViceId;
	afs_int32 BeginTimestamp;
	afs_int32 EndTimestamp;
};
typedef struct PAGCB_ClearToken PAGCB_ClearToken;
bool_t xdr_PAGCB_ClearToken(XDR *xdrs, PAGCB_ClearToken *objp);


struct CredInfo {
	char *cellname;
	afs_int32 vid;
	afs_int32 states;
	PAGCB_ClearToken ct;
	struct st {
		u_int st_len;
		char *st_val;
	} st;
};
typedef struct CredInfo CredInfo;
bool_t xdr_CredInfo(XDR *xdrs, CredInfo *objp);


typedef struct CredInfos {
	u_int CredInfos_len;
	CredInfo *CredInfos_val;
} CredInfos;
bool_t xdr_CredInfos(XDR *xdrs, CredInfos *objp);


struct SysNameEnt {
	char *sysname;
};
typedef struct SysNameEnt SysNameEnt;
bool_t xdr_SysNameEnt(XDR *xdrs, SysNameEnt *objp);


typedef struct SysNameList {
	u_int SysNameList_len;
	SysNameEnt *SysNameList_val;
} SysNameList;
bool_t xdr_SysNameList(XDR *xdrs, SysNameList *objp);


extern int PAGCB_GetCreds(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 uid,
	/*OUT*/ CredInfos * creds);

extern afs_int32 SPAGCB_GetCreds(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 uid,
	/*OUT*/ CredInfos * creds);

extern int PAGCB_GetSysName(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 uid,
	/*OUT*/ SysNameList * sysnames);

extern afs_int32 SPAGCB_GetSysName(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 uid,
	/*OUT*/ SysNameList * sysnames);

extern int PAGCB_ExecuteRequest(struct rx_call *);

/* Opcode-related useful stats for package: PAGCB_ */
#define PAGCB_LOWEST_OPCODE   1
#define PAGCB_HIGHEST_OPCODE	2
#define PAGCB_NUMBER_OPCODES	2

#define PAGCB_NO_OF_STAT_FUNCS	2

AFS_RXGEN_EXPORT
extern const char *PAGCB_function_names[];

#endif	/* _RXGEN_PAGCB_ */
