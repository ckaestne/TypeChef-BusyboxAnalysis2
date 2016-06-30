/*
 * budb_errs.h:
 * This file is automatically generated; please do not edit it.
 */
#define BUDB_DUMPIDEXISTS                        (156303872L)
#define BUDB_NODUMPID                            (156303873L)
#define BUDB_NODUMPNAME                          (156303874L)
#define BUDB_NOTAPENAME                          (156303875L)
#define BUDB_NOVOLUMENAME                        (156303876L)
#define BUDB_NOENT                               (156303877L)
#define BUDB_TAPENOTINUSE                        (156303878L)
#define BUDB_DUMPFAILED                          (156303879L)
#define BUDB_NOTPERMITTED                        (156303880L)
#define BUDB_VERSIONMISMATCH                     (156303881L)
#define BUDB_BADARGUMENT                         (156303882L)
#define BUDB_BADPROTOCOL                         (156303883L)
#define BUDB_BADFLAGS                            (156303884L)
#define BUDB_LIST2BIG                            (156303885L)
#define BUDB_ENDOFLIST                           (156303886L)
#define BUDB_BLOCKTYPE                           (156303887L)
#define BUDB_NOTLOCKED                           (156303888L)
#define BUDB_LOCKED                              (156303889L)
#define BUDB_SELFLOCKED                          (156303890L)
#define BUDB_OLDINTERFACE                        (156303891L)
#define BUDB_IO                                  (156303892L)
#define BUDB_ADDR                                (156303893L)
#define BUDB_DATABASEINCONSISTENT                (156303894L)
#define BUDB_INTERNALERROR                       (156303895L)
#define BUDB_NOCELLS                             (156303896L)
#define BUDB_NOCELL                              (156303897L)
#define BUDB_EMPTY                               (156303898L)
#define BUDB_UBIKINIT                            (156303899L)
#define BUDB_ALLOCFAIL                           (156303900L)
#define BUDB_NOMEM                               (156303901L)
#define BUDB_NOTINITIALDUMP                      (156303902L)
#define BUDB_DUMPNOTINUSE                        (156303903L)
extern void initialize_BUDB_error_table(void);
#define ERROR_TABLE_BASE_BUDB (156303872L)

/* for compatibility with older versions... */
#define init_BUDB_err_tbl initialize_BUDB_error_table
#define BUDB_err_base ERROR_TABLE_BASE_BUDB

/* for compatibility with other users... */
#define ERROR_TABLE_BASE_budb (156303872L)
#define init_budb_err_tbl initialize_BUDB_error_table
#define initialize_budb_error_table initialize_BUDB_error_table
#define budb_err_base ERROR_TABLE_BASE_budb
