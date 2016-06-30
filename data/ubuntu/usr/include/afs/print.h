/* Machine generated file -- Do NOT edit */

#ifndef	_RXGEN_PTINT_
#define	_RXGEN_PTINT_

#ifdef	KERNEL
/* The following 'ifndefs' are not a good solution to the vendor's omission of surrounding all system includes with 'ifndef's since it requires that this file is included after the system includes...*/
#include <afsconfig.h>
#include "afs/param.h"
#ifdef	UKERNEL
#include "afs/sysincludes.h"
#include "rx/xdr.h"
#include "rx/rx.h"
#include "rx/rx_globals.h"
#include <ubik.h>
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
#include <ubik.h>
#endif	/* KERNEL */

#ifdef AFS_NT40_ENV
#ifndef AFS_RXGEN_EXPORT
#define AFS_RXGEN_EXPORT __declspec(dllimport)
#endif /* AFS_RXGEN_EXPORT */
#else /* AFS_NT40_ENV */
#define AFS_RXGEN_EXPORT
#endif /* AFS_NT40_ENV */

#define PR_STATINDEX 8
#define PRSUCCESS 0
#define PR_MAXNAMELEN 64
#define PR_MAXGROUPS 5000
#define PR_MAXLIST 5000
#define PRSIZE 10
#define COSIZE 39

struct prdebugentry {
	afs_int32 flags;
	afs_int32 id;
	afs_int32 cellid;
	afs_int32 next;
	afs_int32 reserved[5];
	afs_int32 entries[PRSIZE];
	afs_int32 nextID;
	afs_int32 nextname;
	afs_int32 owner;
	afs_int32 creator;
	afs_int32 ngroups;
	afs_int32 nusers;
	afs_int32 count;
	afs_int32 instance;
	afs_int32 owned;
	afs_int32 nextOwned;
	afs_int32 parent;
	afs_int32 sibling;
	afs_int32 child;
	char name[PR_MAXNAMELEN];
};
typedef struct prdebugentry prdebugentry;
bool_t xdr_prdebugentry(XDR *xdrs, prdebugentry *objp);


struct prcheckentry {
	afs_int32 flags;
	afs_int32 id;
	afs_int32 owner;
	afs_int32 creator;
	afs_int32 ngroups;
	afs_int32 nusers;
	afs_int32 count;
	afs_int32 reserved[5];
	char name[PR_MAXNAMELEN];
};
typedef struct prcheckentry prcheckentry;
bool_t xdr_prcheckentry(XDR *xdrs, prcheckentry *objp);


struct prlistentries {
	afs_int32 flags;
	afs_int32 id;
	afs_int32 owner;
	afs_int32 creator;
	afs_int32 ngroups;
	afs_int32 nusers;
	afs_int32 count;
	afs_int32 reserved[5];
	char name[PR_MAXNAMELEN];
};
typedef struct prlistentries prlistentries;
bool_t xdr_prlistentries(XDR *xdrs, prlistentries *objp);


struct PrUpdateEntry {
	afs_uint32 Mask;
	afs_int32 flags;
	afs_int32 id;
	afs_int32 owner;
	afs_int32 creator;
	afs_int32 ngroups;
	afs_int32 nusers;
	afs_int32 count;
	afs_int32 reserved[5];
	char name[PR_MAXNAMELEN];
};
typedef struct PrUpdateEntry PrUpdateEntry;
bool_t xdr_PrUpdateEntry(XDR *xdrs, PrUpdateEntry *objp);

#define PRUPDATE_NAME 0x0001
#define PRUPDATE_ID 0x0002
#define PRUPDATE_FLAGS 0x0004
#define PRUPDATE_NAMEHASH 0x0008
#define PRUPDATE_IDHASH 0x0010
#define PR_SF_ALLBITS 0xff /* set all access bits */
#define PR_SF_NGROUPS (1<<31) /* set field limiting group creation */
#define PR_SF_NUSERS (1<<30) /*  "  "  foreign users  "  */

typedef char prname[PR_MAXNAMELEN];
bool_t xdr_prname(XDR *xdrs, prname *objp);


typedef struct namelist {
	u_int namelist_len;
	prname *namelist_val;
} namelist;
bool_t xdr_namelist(XDR *xdrs, namelist *objp);


typedef struct idlist {
	u_int idlist_len;
	afs_int32 *idlist_val;
} idlist;
bool_t xdr_idlist(XDR *xdrs, idlist *objp);


typedef struct prlist {
	u_int prlist_len;
	afs_int32 *prlist_val;
} prlist;
bool_t xdr_prlist(XDR *xdrs, prlist *objp);


typedef struct prentries {
	u_int prentries_len;
	prlistentries *prentries_val;
} prentries;
bool_t xdr_prentries(XDR *xdrs, prentries *objp);


extern int PR_INewEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * name,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 oid);

extern int ubik_PR_INewEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ char * name,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 oid);

extern afs_int32 SPR_INewEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * name,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 oid);

extern int PR_WhereIsIt(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 id,
	/*OUT*/ afs_int32 * ps);

extern int ubik_PR_WhereIsIt(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 id,
	/*OUT*/ afs_int32 * ps);

extern afs_int32 SPR_WhereIsIt(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 id,
	/*OUT*/ afs_int32 * ps);

extern int PR_DumpEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 pos,
	/*OUT*/ struct prdebugentry * entry);

extern int ubik_PR_DumpEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 pos,
	/*OUT*/ struct prdebugentry * entry);

extern afs_int32 SPR_DumpEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 pos,
	/*OUT*/ struct prdebugentry * entry);

extern int PR_AddToGroup(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 uid,
	/*IN */ afs_int32 gid);

extern int ubik_PR_AddToGroup(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 uid,
	/*IN */ afs_int32 gid);

extern afs_int32 SPR_AddToGroup(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 uid,
	/*IN */ afs_int32 gid);

extern int PR_NameToID(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ namelist * nlist,
	/*OUT*/ idlist * ilist);

extern int ubik_PR_NameToID(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ namelist * nlist,
	/*OUT*/ idlist * ilist);

extern afs_int32 SPR_NameToID(
	/*IN */ struct rx_call *z_call,
	/*IN */ namelist * nlist,
	/*OUT*/ idlist * ilist);

extern int PR_IDToName(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ idlist * ilist,
	/*OUT*/ namelist * nlist);

extern int ubik_PR_IDToName(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ idlist * ilist,
	/*OUT*/ namelist * nlist);

extern afs_int32 SPR_IDToName(
	/*IN */ struct rx_call *z_call,
	/*IN */ idlist * ilist,
	/*OUT*/ namelist * nlist);

extern int PR_Delete(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 id);

extern int ubik_PR_Delete(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 id);

extern afs_int32 SPR_Delete(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 id);

extern int PR_RemoveFromGroup(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 gid);

extern int ubik_PR_RemoveFromGroup(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 gid);

extern afs_int32 SPR_RemoveFromGroup(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 gid);

extern int PR_GetCPS(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 id,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern int ubik_PR_GetCPS(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 id,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern afs_int32 SPR_GetCPS(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 id,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern int PR_NewEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * name,
	/*IN */ afs_int32 flag,
	/*IN */ afs_int32 oid,
	/*OUT*/ afs_int32 * id);

extern int ubik_PR_NewEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ char * name,
	/*IN */ afs_int32 flag,
	/*IN */ afs_int32 oid,
	/*OUT*/ afs_int32 * id);

extern afs_int32 SPR_NewEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * name,
	/*IN */ afs_int32 flag,
	/*IN */ afs_int32 oid,
	/*OUT*/ afs_int32 * id);

extern int PR_ListMax(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ afs_int32 * uid,
	/*OUT*/ afs_int32 * gid);

extern int ubik_PR_ListMax(
	struct ubik_client *aclient, afs_int32 aflags,
	/*OUT*/ afs_int32 * uid,
	/*OUT*/ afs_int32 * gid);

extern afs_int32 SPR_ListMax(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_int32 * uid,
	/*OUT*/ afs_int32 * gid);

extern int PR_SetMax(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 gflag);

extern int ubik_PR_SetMax(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 gflag);

extern afs_int32 SPR_SetMax(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 gflag);

extern int PR_ListEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 id,
	/*OUT*/ struct prcheckentry * entry);

extern int ubik_PR_ListEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 id,
	/*OUT*/ struct prcheckentry * entry);

extern afs_int32 SPR_ListEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 id,
	/*OUT*/ struct prcheckentry * entry);

extern int PR_ChangeEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 id,
	/*IN */ char * name,
	/*IN */ afs_int32 oid,
	/*IN */ afs_int32 newid);

extern int ubik_PR_ChangeEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 id,
	/*IN */ char * name,
	/*IN */ afs_int32 oid,
	/*IN */ afs_int32 newid);

extern afs_int32 SPR_ChangeEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 id,
	/*IN */ char * name,
	/*IN */ afs_int32 oid,
	/*IN */ afs_int32 newid);

extern int PR_ListElements(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 id,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern int ubik_PR_ListElements(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 id,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern afs_int32 SPR_ListElements(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 id,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern int PR_IsAMemberOf(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 uid,
	/*IN */ afs_int32 gid,
	/*OUT*/ afs_int32 * flag);

extern int ubik_PR_IsAMemberOf(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 uid,
	/*IN */ afs_int32 gid,
	/*OUT*/ afs_int32 * flag);

extern afs_int32 SPR_IsAMemberOf(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 uid,
	/*IN */ afs_int32 gid,
	/*OUT*/ afs_int32 * flag);

extern int PR_SetFieldsEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 mask,
	/*IN */ afs_int32 flags,
	/*IN */ afs_int32 ngroups,
	/*IN */ afs_int32 nusers,
	/*IN */ afs_int32 spare1,
	/*IN */ afs_int32 spare2);

extern int ubik_PR_SetFieldsEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 mask,
	/*IN */ afs_int32 flags,
	/*IN */ afs_int32 ngroups,
	/*IN */ afs_int32 nusers,
	/*IN */ afs_int32 spare1,
	/*IN */ afs_int32 spare2);

extern afs_int32 SPR_SetFieldsEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 mask,
	/*IN */ afs_int32 flags,
	/*IN */ afs_int32 ngroups,
	/*IN */ afs_int32 nusers,
	/*IN */ afs_int32 spare1,
	/*IN */ afs_int32 spare2);

extern int PR_ListOwned(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 id,
	/*OUT*/ prlist * elist,
	/*I/O*/ afs_int32 * lastp);

extern int ubik_PR_ListOwned(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 id,
	/*OUT*/ prlist * elist,
	/*I/O*/ afs_int32 * lastp);

extern afs_int32 SPR_ListOwned(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 id,
	/*OUT*/ prlist * elist,
	/*I/O*/ afs_int32 * lastp);

extern int PR_GetCPS2(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 host,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern int ubik_PR_GetCPS2(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 host,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern afs_int32 SPR_GetCPS2(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 id,
	/*IN */ afs_int32 host,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern int PR_GetHostCPS(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 host,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern int ubik_PR_GetHostCPS(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 host,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern afs_int32 SPR_GetHostCPS(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 host,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern int PR_UpdateEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 id,
	/*IN */ char * name,
	/*IN */ PrUpdateEntry * uentry);

extern int ubik_PR_UpdateEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 id,
	/*IN */ char * name,
	/*IN */ PrUpdateEntry * uentry);

extern afs_int32 SPR_UpdateEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 id,
	/*IN */ char * name,
	/*IN */ PrUpdateEntry * uentry);

extern int PR_ListEntries(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 flags,
	/*IN */ afs_int32 startindex,
	/*OUT*/ prentries * bulkentries,
	/*OUT*/ afs_int32 * nextstartindex);

extern int ubik_PR_ListEntries(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 flags,
	/*IN */ afs_int32 startindex,
	/*OUT*/ prentries * bulkentries,
	/*OUT*/ afs_int32 * nextstartindex);

extern afs_int32 SPR_ListEntries(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 flags,
	/*IN */ afs_int32 startindex,
	/*OUT*/ prentries * bulkentries,
	/*OUT*/ afs_int32 * nextstartindex);

extern int PR_ListSuperGroups(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 id,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern int ubik_PR_ListSuperGroups(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 id,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern afs_int32 SPR_ListSuperGroups(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 id,
	/*OUT*/ prlist * elist,
	/*OUT*/ afs_int32 * over);

extern int PR_ExecuteRequest(struct rx_call *);

/* Opcode-related useful stats for package: PR_ */
#define PR_LOWEST_OPCODE   500
#define PR_HIGHEST_OPCODE	530
#define PR_NUMBER_OPCODES	23

#define PR_NO_OF_STAT_FUNCS	23

AFS_RXGEN_EXPORT
extern const char *PR_function_names[];

#endif	/* _RXGEN_PTINT_ */
