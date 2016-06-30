/*
 * pterror.h:
 * This file is automatically generated; please do not edit it.
 */
#define PREXIST                                  (267264L)
#define PRIDEXIST                                (267265L)
#define PRNOIDS                                  (267266L)
#define PRDBFAIL                                 (267267L)
#define PRNOENT                                  (267268L)
#define PRPERM                                   (267269L)
#define PRNOTGROUP                               (267270L)
#define PRNOTUSER                                (267271L)
#define PRBADNAM                                 (267272L)
#define PRBADARG                                 (267273L)
#define PRNOMORE                                 (267274L)
#define PRDBBAD                                  (267275L)
#define PRGROUPEMPTY                             (267276L)
#define PRINCONSISTENT                           (267277L)
#define PRDBADDR                                 (267278L)
#define PRTOOMANY                                (267279L)
#define PRNOMEM                                  (267280L)
extern void initialize_PT_error_table(void);
#define ERROR_TABLE_BASE_PT (267264L)

/* for compatibility with older versions... */
#define init_PT_err_tbl initialize_PT_error_table
#define PT_err_base ERROR_TABLE_BASE_PT

/* for compatibility with other users... */
#define ERROR_TABLE_BASE_pt (267264L)
#define init_pt_err_tbl initialize_PT_error_table
#define initialize_pt_error_table initialize_PT_error_table
#define pt_err_base ERROR_TABLE_BASE_pt
