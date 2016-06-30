/* Machine generated file -- Do NOT edit */

#ifndef	_RXGEN_KAUTH_
#define	_RXGEN_KAUTH_

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


struct ka_CBS {
	afs_int32 SeqLen;
	char *SeqBody;
};
typedef struct ka_CBS ka_CBS;
bool_t xdr_ka_CBS(XDR *xdrs, ka_CBS *objp);


struct ka_BBS {
	afs_int32 MaxSeqLen;
	afs_int32 SeqLen;
	char *SeqBody;
};
typedef struct ka_BBS ka_BBS;
bool_t xdr_ka_BBS(XDR *xdrs, ka_BBS *objp);

#define MAXKAKVNO 127
#define KAFNORMAL 0x001
#define KAFFREE 0x002
#define KAFOLDKEYS 0x010
#define KAFSPECIAL 0x100
#define KAFASSOCROOT 0x200
#define KAFASSOC 0x400
#define KAFADMIN 0x004
#define KAFNOTGS 0x008
#define KAFNOSEAL 0x020
#define KAFNOCPW 0x040
#define KAFNEWASSOC 0x080
#define KAF_SETTABLE_FLAGS (KAFADMIN | KAFNOTGS | KAFNOSEAL | KAFNOCPW | KAFNEWASSOC)

struct EncryptionKey {
	char key[8];
};
typedef struct EncryptionKey EncryptionKey;
bool_t xdr_EncryptionKey(XDR *xdrs, EncryptionKey *objp);

#define KAMAJORVERSION 5
#define KAMINORVERSION 2
#ifndef NEVERDATE
#define NEVERDATE 037777777777 /* a date that will never come */
#endif
#ifndef Date
#define Date afs_uint32
#endif
#if !defined(AFS_HPUX_ENV) && !defined(AFS_NT40_ENV) && !defined(AFS_LINUX20_ENV)
#define AUTH_DBM_LOG
#endif

typedef char *kaname;
bool_t xdr_kaname(XDR *xdrs, kaname *objp);


struct kaident {
	char name[64];
	char instance[64];
};
typedef struct kaident kaident;
bool_t xdr_kaident(XDR *xdrs, kaident *objp);


struct kaentryinfo {
	afs_int32 minor_version;
	afs_int32 flags;
	afs_uint32 user_expiration;
	afs_uint32 modification_time;
	struct kaident modification_user;
	afs_uint32 change_password_time;
	afs_int32 max_ticket_lifetime;
	afs_int32 key_version;
	EncryptionKey key;
	afs_uint32 keyCheckSum;
	afs_uint32 misc_auth_bytes;
	afs_int32 reserved3;
	afs_int32 reserved4;
};
typedef struct kaentryinfo kaentryinfo;
bool_t xdr_kaentryinfo(XDR *xdrs, kaentryinfo *objp);


struct kasstats {
	afs_int32 minor_version;
	afs_int32 allocs;
	afs_int32 frees;
	afs_int32 cpws;
	afs_int32 reserved1;
	afs_int32 reserved2;
	afs_int32 reserved3;
	afs_int32 reserved4;
};
typedef struct kasstats kasstats;
bool_t xdr_kasstats(XDR *xdrs, kasstats *objp);


struct katimeval {
	afs_int32 tv_sec;
	afs_int32 tv_usec;
};
typedef struct katimeval katimeval;
bool_t xdr_katimeval(XDR *xdrs, katimeval *objp);


struct karpcstats {
	int requests;
	int aborts;
};
typedef struct karpcstats karpcstats;
bool_t xdr_karpcstats(XDR *xdrs, karpcstats *objp);


struct kadstats {
	afs_int32 minor_version;
	afs_int32 host;
	afs_uint32 start_time;
	afs_int32 hashTableUtilization;
	struct karpcstats Authenticate;
	struct karpcstats ChangePassword;
	struct karpcstats GetTicket;
	struct karpcstats CreateUser;
	struct karpcstats SetPassword;
	struct karpcstats SetFields;
	struct karpcstats DeleteUser;
	struct karpcstats GetEntry;
	struct karpcstats ListEntry;
	struct karpcstats GetStats;
	struct karpcstats GetPassword;
	struct karpcstats GetRandomKey;
	struct karpcstats Debug;
	struct karpcstats UAuthenticate;
	struct karpcstats UGetTicket;
	struct karpcstats Unlock;
	struct karpcstats LockStatus;
	afs_int32 string_checks;
	afs_int32 reserved1;
	afs_int32 reserved2;
	afs_int32 reserved3;
	afs_int32 reserved4;
};
typedef struct kadstats kadstats;
bool_t xdr_kadstats(XDR *xdrs, kadstats *objp);

#define KADEBUGKCINFOSIZE 25

struct ka_kcInfo {
	afs_uint32 used;
	afs_int32 kvno;
	char primary;
	char keycksum;
	char principal[64];
};
typedef struct ka_kcInfo ka_kcInfo;
bool_t xdr_ka_kcInfo(XDR *xdrs, ka_kcInfo *objp);


struct ka_debugInfo {
	afs_int32 minorVersion;
	afs_int32 host;
	afs_uint32 startTime;
	int noAuth;
	afs_uint32 lastTrans;
	char lastOperation[16];
	char lastAuth[256];
	char lastUAuth[256];
	char lastTGS[256];
	char lastUTGS[256];
	char lastAdmin[256];
	char lastTGSServer[256];
	char lastUTGSServer[256];
	afs_uint32 nextAutoCPW;
	int updatesRemaining;
	afs_uint32 dbHeaderRead;
	afs_int32 dbVersion;
	afs_int32 dbFreePtr;
	afs_int32 dbEofPtr;
	afs_int32 dbKvnoPtr;
	afs_int32 dbSpecialKeysVersion;
	afs_int32 cheader_lock;
	afs_int32 keycache_lock;
	afs_int32 kcVersion;
	int kcSize;
	int kcUsed;
	struct ka_kcInfo kcInfo[KADEBUGKCINFOSIZE];
	afs_int32 reserved1;
	afs_int32 reserved2;
	afs_int32 reserved3;
	afs_int32 reserved4;
};
typedef struct ka_debugInfo ka_debugInfo;
bool_t xdr_ka_debugInfo(XDR *xdrs, ka_debugInfo *objp);

#define KAA_STATINDEX 18

extern int KAA_Authenticate_old(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_uint32 start_time,
	/*IN */ afs_uint32 end_time,
	/*IN */ struct ka_CBS * request,
	/*I/O*/ struct ka_BBS * answer);

extern int ubik_KAA_Authenticate_old(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_uint32 start_time,
	/*IN */ afs_uint32 end_time,
	/*IN */ struct ka_CBS * request,
	/*I/O*/ struct ka_BBS * answer);

extern afs_int32 SKAA_Authenticate_old(
	/*IN */ struct rx_call *z_call,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_uint32 start_time,
	/*IN */ afs_uint32 end_time,
	/*IN */ struct ka_CBS * request,
	/*I/O*/ struct ka_BBS * answer);

extern int KAA_Authenticate(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_uint32 start_time,
	/*IN */ afs_uint32 end_time,
	/*IN */ struct ka_CBS * request,
	/*I/O*/ struct ka_BBS * answer);

extern int ubik_KAA_Authenticate(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_uint32 start_time,
	/*IN */ afs_uint32 end_time,
	/*IN */ struct ka_CBS * request,
	/*I/O*/ struct ka_BBS * answer);

extern afs_int32 SKAA_Authenticate(
	/*IN */ struct rx_call *z_call,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_uint32 start_time,
	/*IN */ afs_uint32 end_time,
	/*IN */ struct ka_CBS * request,
	/*I/O*/ struct ka_BBS * answer);

extern int KAA_AuthenticateV2(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_uint32 start_time,
	/*IN */ afs_uint32 end_time,
	/*IN */ struct ka_CBS * request,
	/*I/O*/ struct ka_BBS * answer);

extern int ubik_KAA_AuthenticateV2(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_uint32 start_time,
	/*IN */ afs_uint32 end_time,
	/*IN */ struct ka_CBS * request,
	/*I/O*/ struct ka_BBS * answer);

extern afs_int32 SKAA_AuthenticateV2(
	/*IN */ struct rx_call *z_call,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_uint32 start_time,
	/*IN */ afs_uint32 end_time,
	/*IN */ struct ka_CBS * request,
	/*I/O*/ struct ka_BBS * answer);

extern int KAA_ChangePassword(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ struct ka_CBS * arequest,
	/*I/O*/ struct ka_BBS * oanswer);

extern int ubik_KAA_ChangePassword(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ struct ka_CBS * arequest,
	/*I/O*/ struct ka_BBS * oanswer);

extern afs_int32 SKAA_ChangePassword(
	/*IN */ struct rx_call *z_call,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ struct ka_CBS * arequest,
	/*I/O*/ struct ka_BBS * oanswer);
#define KAT_STATINDEX 19

extern int KAT_GetTicket_old(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 kvno,
	/*IN */ kaname auth_domain,
	/*IN */ struct ka_CBS * aticket,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ struct ka_CBS * atimes,
	/*I/O*/ struct ka_BBS * oanswer);

extern int ubik_KAT_GetTicket_old(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 kvno,
	/*IN */ kaname auth_domain,
	/*IN */ struct ka_CBS * aticket,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ struct ka_CBS * atimes,
	/*I/O*/ struct ka_BBS * oanswer);

extern afs_int32 SKAT_GetTicket_old(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 kvno,
	/*IN */ kaname auth_domain,
	/*IN */ struct ka_CBS * aticket,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ struct ka_CBS * atimes,
	/*I/O*/ struct ka_BBS * oanswer);

extern int KAT_GetTicket(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 kvno,
	/*IN */ kaname auth_domain,
	/*IN */ struct ka_CBS * aticket,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ struct ka_CBS * atimes,
	/*I/O*/ struct ka_BBS * oanswer);

extern int ubik_KAT_GetTicket(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 kvno,
	/*IN */ kaname auth_domain,
	/*IN */ struct ka_CBS * aticket,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ struct ka_CBS * atimes,
	/*I/O*/ struct ka_BBS * oanswer);

extern afs_int32 SKAT_GetTicket(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 kvno,
	/*IN */ kaname auth_domain,
	/*IN */ struct ka_CBS * aticket,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ struct ka_CBS * atimes,
	/*I/O*/ struct ka_BBS * oanswer);
#define KAM_STATINDEX 20

extern int KAM_SetPassword(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_int32 kvno,
	/*IN */ EncryptionKey password);

extern int ubik_KAM_SetPassword(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_int32 kvno,
	/*IN */ EncryptionKey password);

extern afs_int32 SKAM_SetPassword(
	/*IN */ struct rx_call *z_call,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_int32 kvno,
	/*IN */ EncryptionKey password);

extern int KAM_SetFields(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_int32 flags,
	/*IN */ afs_uint32 user_expiration,
	/*IN */ afs_int32 max_ticket_lifetime,
	/*IN */ afs_int32 maxAssociates,
	/*IN */ afs_uint32 misc_auth_bytes,
	/*IN */ afs_int32 spare2);

extern int ubik_KAM_SetFields(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_int32 flags,
	/*IN */ afs_uint32 user_expiration,
	/*IN */ afs_int32 max_ticket_lifetime,
	/*IN */ afs_int32 maxAssociates,
	/*IN */ afs_uint32 misc_auth_bytes,
	/*IN */ afs_int32 spare2);

extern afs_int32 SKAM_SetFields(
	/*IN */ struct rx_call *z_call,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_int32 flags,
	/*IN */ afs_uint32 user_expiration,
	/*IN */ afs_int32 max_ticket_lifetime,
	/*IN */ afs_int32 maxAssociates,
	/*IN */ afs_uint32 misc_auth_bytes,
	/*IN */ afs_int32 spare2);

extern int KAM_CreateUser(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ EncryptionKey password);

extern int ubik_KAM_CreateUser(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ EncryptionKey password);

extern afs_int32 SKAM_CreateUser(
	/*IN */ struct rx_call *z_call,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ EncryptionKey password);

extern int KAM_DeleteUser(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ kaname name,
	/*IN */ kaname instance);

extern int ubik_KAM_DeleteUser(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ kaname name,
	/*IN */ kaname instance);

extern afs_int32 SKAM_DeleteUser(
	/*IN */ struct rx_call *z_call,
	/*IN */ kaname name,
	/*IN */ kaname instance);

extern int KAM_GetEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_int32 major_version,
	/*OUT*/ struct kaentryinfo * entry);

extern int ubik_KAM_GetEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_int32 major_version,
	/*OUT*/ struct kaentryinfo * entry);

extern afs_int32 SKAM_GetEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_int32 major_version,
	/*OUT*/ struct kaentryinfo * entry);

extern int KAM_ListEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 previous_index,
	/*OUT*/ afs_int32 * index,
	/*OUT*/ afs_int32 * count,
	/*OUT*/ kaident * name);

extern int ubik_KAM_ListEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 previous_index,
	/*OUT*/ afs_int32 * index,
	/*OUT*/ afs_int32 * count,
	/*OUT*/ kaident * name);

extern afs_int32 SKAM_ListEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 previous_index,
	/*OUT*/ afs_int32 * index,
	/*OUT*/ afs_int32 * count,
	/*OUT*/ kaident * name);

extern int KAM_GetStats(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 major_version,
	/*OUT*/ afs_int32 * admin_accounts,
	/*OUT*/ struct kasstats * statics,
	/*OUT*/ struct kadstats * dynamics);

extern int ubik_KAM_GetStats(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 major_version,
	/*OUT*/ afs_int32 * admin_accounts,
	/*OUT*/ struct kasstats * statics,
	/*OUT*/ struct kadstats * dynamics);

extern afs_int32 SKAM_GetStats(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 major_version,
	/*OUT*/ afs_int32 * admin_accounts,
	/*OUT*/ struct kasstats * statics,
	/*OUT*/ struct kadstats * dynamics);

extern int KAM_Debug(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 major_version,
	/*IN */ int checkDB,
	/*OUT*/ struct ka_debugInfo * info);

extern int ubik_KAM_Debug(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 major_version,
	/*IN */ int checkDB,
	/*OUT*/ struct ka_debugInfo * info);

extern afs_int32 SKAM_Debug(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 major_version,
	/*IN */ int checkDB,
	/*OUT*/ struct ka_debugInfo * info);

extern int KAM_GetPassword(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ kaname name,
	/*OUT*/ EncryptionKey * password);

extern int ubik_KAM_GetPassword(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ kaname name,
	/*OUT*/ EncryptionKey * password);

extern afs_int32 SKAM_GetPassword(
	/*IN */ struct rx_call *z_call,
	/*IN */ kaname name,
	/*OUT*/ EncryptionKey * password);

extern int KAM_GetRandomKey(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ EncryptionKey * password);

extern int ubik_KAM_GetRandomKey(
	struct ubik_client *aclient, afs_int32 aflags,
	/*OUT*/ EncryptionKey * password);

extern afs_int32 SKAM_GetRandomKey(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ EncryptionKey * password);

extern int KAM_Unlock(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_int32 spare1,
	/*IN */ afs_int32 spare2,
	/*IN */ afs_int32 spare3,
	/*IN */ afs_int32 spare4);

extern int ubik_KAM_Unlock(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_int32 spare1,
	/*IN */ afs_int32 spare2,
	/*IN */ afs_int32 spare3,
	/*IN */ afs_int32 spare4);

extern afs_int32 SKAM_Unlock(
	/*IN */ struct rx_call *z_call,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*IN */ afs_int32 spare1,
	/*IN */ afs_int32 spare2,
	/*IN */ afs_int32 spare3,
	/*IN */ afs_int32 spare4);

extern int KAM_LockStatus(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*OUT*/ afs_int32 * lockeduntil,
	/*IN */ afs_int32 spare1,
	/*IN */ afs_int32 spare2,
	/*IN */ afs_int32 spare3,
	/*IN */ afs_int32 spare4);

extern int ubik_KAM_LockStatus(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*OUT*/ afs_int32 * lockeduntil,
	/*IN */ afs_int32 spare1,
	/*IN */ afs_int32 spare2,
	/*IN */ afs_int32 spare3,
	/*IN */ afs_int32 spare4);

extern afs_int32 SKAM_LockStatus(
	/*IN */ struct rx_call *z_call,
	/*IN */ kaname name,
	/*IN */ kaname instance,
	/*OUT*/ afs_int32 * lockeduntil,
	/*IN */ afs_int32 spare1,
	/*IN */ afs_int32 spare2,
	/*IN */ afs_int32 spare3,
	/*IN */ afs_int32 spare4);

extern int KAA_ExecuteRequest(struct rx_call *);

extern int KAT_ExecuteRequest(struct rx_call *);

extern int KAM_ExecuteRequest(struct rx_call *);

/* Opcode-related useful stats for package: KAA_ */
#define KAA_LOWEST_OPCODE   1
#define KAA_HIGHEST_OPCODE	22
#define KAA_NUMBER_OPCODES	4

#define KAA_NO_OF_STAT_FUNCS	4

AFS_RXGEN_EXPORT
extern const char *KAA_function_names[];


/* Opcode-related useful stats for package: KAT_ */
#define KAT_LOWEST_OPCODE   3
#define KAT_HIGHEST_OPCODE	23
#define KAT_NUMBER_OPCODES	2

#define KAT_NO_OF_STAT_FUNCS	2

AFS_RXGEN_EXPORT
extern const char *KAT_function_names[];


/* Opcode-related useful stats for package: KAM_ */
#define KAM_LOWEST_OPCODE   4
#define KAM_HIGHEST_OPCODE	15
#define KAM_NUMBER_OPCODES	12

#define KAM_NO_OF_STAT_FUNCS	12

AFS_RXGEN_EXPORT
extern const char *KAM_function_names[];

#endif	/* _RXGEN_KAUTH_ */
