/************************************************************************/
/*      H8/3694 Series Include File                        Ver 2.1      */
/************************************************************************/
struct st_lvd {                                         /* struct LVD   */
              union {                                   /* LVDCR        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char LVDE  :1;      /*    LVDE      */
                           unsigned char       :3;      /*              */
                           unsigned char LVDSEL:1;      /*    LVDSEL    */
                           unsigned char LVDRE :1;      /*    LVDRE     */
                           unsigned char LVDDE :1;      /*    LVDDE     */
                           unsigned char LVDUE :1;      /*    LVDUE     */
                           }      BIT;                  /*              */
                    }           CR;                     /*              */
              union {                                   /* LVDSR        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char      :6;       /*              */
                           unsigned char LVDDF:1;       /*    LVDDF     */
                           unsigned char LVDUF:1;       /*    LVDUF     */
                           }      BIT;                  /*              */
                    }           SR;                     /*              */
};                                                      /*              */
struct st_iic2 {                                        /* struct IIC2  */
               union {                                  /* ICCR1        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char ICE :1;       /*    ICE       */
                            unsigned char RCVD:1;       /*    RCVD      */
                            unsigned char MST :1;       /*    MST       */
                            unsigned char TRS :1;       /*    TRS       */
                            unsigned char CKS :4;       /*    CKS       */
                            }      BIT;                 /*              */
                     }          ICCR1;                  /*              */
               union {                                  /* ICCR2        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char BBSY  :1;     /*    BBSY      */
                            unsigned char SCP   :1;     /*    SCP       */
                            unsigned char SDAO  :1;     /*    SDAO      */
                            unsigned char SDAOP :1;     /*    SDAOP     */
                            unsigned char SCLO  :1;     /*    SCLO      */
                            unsigned char       :1;     /*              */
                            unsigned char IICRST:1;     /*    IICRST    */
                            }      BIT;                 /*              */
                     }          ICCR2;                  /*              */
               union {                                  /* ICMR         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char MLS :1;       /*    MLS       */
                            unsigned char WAIT:1;       /*    WAIT      */
                            unsigned char     :2;       /*              */
                            unsigned char BCWP:1;       /*    BCWP      */
                            unsigned char BC  :3;       /*    BC        */
                            }      BIT;                 /*              */
                     }          ICMR;                   /*              */
               union {                                  /* ICIER        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char TIE  :1;      /*    TIE       */
                            unsigned char TEIE :1;      /*    TEIE      */
                            unsigned char RIE  :1;      /*    RIE       */
                            unsigned char NAKIE:1;      /*    NAKIE     */
                            unsigned char STIE :1;      /*    STIE      */
                            unsigned char ACKE :1;      /*    ACKE      */
                            unsigned char ACKBR:1;      /*    ACKBR     */
                            unsigned char ACKBT:1;      /*    ACKBT     */
                            }      BIT;                 /*              */
                     }          ICIER;                  /*              */
               union {                                  /* ICSR         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char TDRE :1;      /*    TDRE      */
                            unsigned char TEND :1;      /*    TEND      */
                            unsigned char RDRF :1;      /*    RDRF      */
                            unsigned char NACKF:1;      /*    NACKF     */
                            unsigned char STOP :1;      /*    STOP      */
                            unsigned char ALOVE:1;      /*    ALOVE     */
                            unsigned char AAS  :1;      /*    AAS       */
                            unsigned char ADZ  :1;      /*    ADZ       */
                            }      BIT;                 /*              */
                     }          ICSR;                   /*              */
               union {                                  /* SAR          */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char SVA:7;        /*    SVA       */
                            unsigned char FS :1;        /*    FS        */
                            }      BIT;                 /*              */
                     }          SAR;                    /*              */
               unsigned char    ICDRT;                  /* ICDRT        */
               unsigned char    ICDRR;                  /* ICDRR        */
};                                                      /*              */
struct st_tw {                                          /* struct TW    */
             union {                                    /* TMRW         */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char CTS  :1;        /*    CTS       */
                          unsigned char      :1;        /*              */
                          unsigned char BUFEB:1;        /*    BUFEB     */
                          unsigned char BUFEA:1;        /*    BUFEA     */
                          unsigned char      :1;        /*              */
                          unsigned char PWMD :1;        /*    PWMD      */
                          unsigned char PWMC :1;        /*    PWMC      */
                          unsigned char PWMB :1;        /*    PWMB      */
                          }      BIT;                   /*              */
                   }            TMRW;                   /*              */
             union {                                    /* TCRW         */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char CCLR:1;         /*    CCLR      */
                          unsigned char CKS :3;         /*    CKS       */
                          unsigned char TOD :1;         /*    TOD       */
                          unsigned char TOC :1;         /*    TOC       */
                          unsigned char TOB :1;         /*    TOB       */
                          unsigned char TOA :1;         /*    TOA       */
                          }      BIT;                   /*              */
                   }            TCRW;                   /*              */
             union {                                    /* TIERW        */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char OVIE :1;        /*    OVIE      */
                          unsigned char      :3;        /*              */
                          unsigned char IMIED:1;        /*    IMIED     */
                          unsigned char IMIEC:1;        /*    IMIEC     */
                          unsigned char IMIEB:1;        /*    IMIEB     */
                          unsigned char IMIEA:1;        /*    IMIEA     */
                          }      BIT;                   /*              */
                   }            TIERW;                  /*              */
             union {                                    /* TSRW         */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char OVF :1;         /*    OVF       */
                          unsigned char     :3;         /*              */
                          unsigned char IMFD:1;         /*    IMFD      */
                          unsigned char IMFC:1;         /*    IMFC      */
                          unsigned char IMFB:1;         /*    IMFB      */
                          unsigned char IMFA:1;         /*    IMFA      */
                          }      BIT;                   /*              */
                   }            TSRW;                   /*              */
             union {                                    /* TIOR0        */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char    :1;          /*              */
                          unsigned char IOB:3;          /*    IOB       */
                          unsigned char    :1;          /*              */
                          unsigned char IOA:3;          /*    IOA       */
                          }      BIT;                   /*              */
                   }            TIOR0;                  /*              */
             union {                                    /* TIOR1        */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char    :1;          /*              */
                          unsigned char IOD:3;          /*    IOD       */
                          unsigned char    :1;          /*              */
                          unsigned char IOC:3;          /*    IOC       */
                          }      BIT;                   /*              */
                   }            TIOR1;                  /*              */
             unsigned int       TCNT;                   /* TCNT         */
             unsigned int       GRA;                    /* GRA          */
             unsigned int       GRB;                    /* GRB          */
             unsigned int       GRC;                    /* GRC          */
             unsigned int       GRD;                    /* GRD          */
};                                                      /*              */
struct st_flash {                                       /* struct FLASH */
                union {                                 /* FLMCR1       */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char    :1;       /*              */
                             unsigned char SWE:1;       /*    SWE       */
                             unsigned char ESU:1;       /*    ESU       */
                             unsigned char PSU:1;       /*    PSU       */
                             unsigned char EV :1;       /*    EV        */
                             unsigned char PV :1;       /*    PV        */
                             unsigned char E  :1;       /*    E         */
                             unsigned char P  :1;       /*    P         */
                             }      BIT;                /*              */
                      }         FLMCR1;                 /*              */
                union {                                 /* FLMCR2       */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char FLER:1;      /*    FLER      */
                             }      BIT;                /*              */
                      }         FLMCR2;                 /*              */
                union {                                 /* FLPWCR       */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char PDWND:1;     /*    PDWND     */
                             }      BIT;                /*              */
                      }         FLPWCR;                 /*              */
                union {                                 /* EBR1         */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char    :3;       /*              */
                             unsigned char EB4:1;       /*    EB4       */
                             unsigned char EB3:1;       /*    EB3       */
                             unsigned char EB2:1;       /*    EB2       */
                             unsigned char EB1:1;       /*    EB1       */
                             unsigned char EB0:1;       /*    EB0       */
                             }      BIT;                /*              */
                      }         EBR1;                   /*              */
                char            wk[7];                  /*              */
                union {                                 /* FENR         */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char FLSHE:1;     /*    FLSHE     */
                             }      BIT;                /*              */
                      }         FENR;                   /*              */
};                                                      /*              */
struct st_tv {                                          /* struct TV    */
             union {                                    /* TCRV0        */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char CMIEB:1;        /*    CMIEB     */
                          unsigned char CMIEA:1;        /*    CMIEA     */
                          unsigned char OVIE :1;        /*    OVIE      */
                          unsigned char CCLR :2;        /*    CCLR      */
                          unsigned char CKS  :3;        /*    CKS       */
                          }      BIT;                   /*              */
                   }            TCRV0;                  /*              */
             union {                                    /* TCSRV        */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char CMFB:1;         /*    CMFB      */
                          unsigned char CMFA:1;         /*    CMFA      */
                          unsigned char OVF :1;         /*    OVF       */
                          unsigned char     :1;         /*              */
                          unsigned char OS  :4;         /*    OS        */
                          }      BIT;                   /*              */
                   }            TCSRV;                  /*              */
             unsigned char      TCORA;                  /* TCORA        */
             unsigned char      TCORB;                  /* TCORB        */
             unsigned char      TCNTV;                  /* TCNT         */
             union {                                    /* TCRV1        */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char     :3;         /*              */
                          unsigned char TVEG:2;         /*    TVEG      */
                          unsigned char TRGE:1;         /*    TRGE      */
                          unsigned char     :1;         /*              */
                          unsigned char ICKS:1;         /*    ICKS      */
                          }      BIT;                   /*              */
                   }            TCRV1;                  /*              */
};                                                      /*              */
struct st_ta {                                          /* struct TA    */
             union {                                    /* TMA          */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char CKSO:3;         /*    CKSO      */
                          unsigned char     :1;         /*              */
                          unsigned char CKSI:4;         /*    CKSI      */
                          }      BIT;                   /*              */
                   }            TMA;                    /*              */
             unsigned char      TCA;                    /* TCA          */
};                                                      /*              */
struct st_sci3 {                                        /* struct SCI3  */
               union {                                  /* SMR          */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char COM :1;       /*    COM       */
                            unsigned char CHR :1;       /*    CHR       */
                            unsigned char PE  :1;       /*    PE        */
                            unsigned char PM  :1;       /*    PM        */
                            unsigned char STOP:1;       /*    STOP      */
                            unsigned char MP  :1;       /*    MP        */
                            unsigned char CKS :2;       /*    CKS       */
                            }      BIT;                 /*              */
                     }          SMR;                    /*              */
               unsigned char    BRR;                    /* BRR          */
               union {                                  /* SCR3         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char TIE :1;       /*    TIE       */
                            unsigned char RIE :1;       /*    RIE       */
                            unsigned char TE  :1;       /*    TE        */
                            unsigned char RE  :1;       /*    RE        */
                            unsigned char MPIE:1;       /*    MPIE      */
                            unsigned char TEIE:1;       /*    TEIE      */
                            unsigned char CKE :2;       /*    CKE       */
                            }      BIT;                 /*              */
                     }          SCR3;                   /*              */
               unsigned char    TDR;                    /* TDR          */
               union {                                  /* SSR          */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char TDRE:1;       /*    TDRE      */
                            unsigned char RDRF:1;       /*    RDRF      */
                            unsigned char OER :1;       /*    OER       */
                            unsigned char FER :1;       /*    FER       */
                            unsigned char PER :1;       /*    PER       */
                            unsigned char TEND:1;       /*    TEND      */
                            unsigned char MPBR:1;       /*    MPBR      */
                            unsigned char MPBT:1;       /*    MPBT      */
                            }      BIT;                 /*              */
                     }          SSR;                    /*              */
               unsigned char    RDR;                    /* RDR          */
};                                                      /*              */
struct st_ad {                                          /* struct A/D   */
             unsigned int       ADDRA;                  /* ADDRA        */
             unsigned int       ADDRB;                  /* ADDRB        */
             unsigned int       ADDRC;                  /* ADDRC        */
             unsigned int       ADDRD;                  /* ADDRD        */
             union {                                    /* ADCSR        */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char ADF :1;         /*    ADF       */
                          unsigned char ADIE:1;         /*    ADIE      */
                          unsigned char ADST:1;         /*    ADST      */
                          unsigned char SCAN:1;         /*    SCAN      */
                          unsigned char CKS :1;         /*    CKS       */
                          unsigned char CH  :3;         /*    CH        */
                          }      BIT;                   /*              */
                   }            ADCSR;                  /*              */
             union {                                    /* ADCR         */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char TRGE:1;         /*    TRGE      */
                          }      BIT;                   /*              */
                   }            ADCR;                   /*              */
};                                                      /*              */
struct st_wdt {                                         /* struct WDT   */
              union {                                   /* TCSRWD       */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char B6WI  :1;      /*    B6WI      */
                           unsigned char TCWE  :1;      /*    TCWE      */
                           unsigned char B4WI  :1;      /*    B4WI      */
                           unsigned char TCSRWE:1;      /*    TCSRWE    */
                           unsigned char B2WI  :1;      /*    B2WI      */
                           unsigned char WDON  :1;      /*    WDON      */
                           unsigned char B0WI  :1;      /*    B0WI      */
                           unsigned char WRST  :1;      /*    WRST      */
                           }      BIT;                  /*              */
                    }           TCSRWD;                 /*              */
              unsigned char     TCWD;                   /* TCWD         */
              union {                                   /* TMWD         */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char    :4;         /*              */
                           unsigned char CKS:4;         /*    CKS       */
                           }      BIT;                  /*              */
                    }           TMWD;                   /*              */
};                                                      /*              */
struct st_abrk {                                        /* struct ABRK  */
               union {                                  /* ABRKCR       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char RTINTE:1;     /*    RTINTE    */
                            unsigned char CSEL  :2;     /*    CSEL      */
                            unsigned char ACMP  :3;     /*    ACMP      */
                            unsigned char DCMP  :2;     /*    DCMP      */
                            }      BIT;                 /*              */
                     }          CR;                     /*              */
               union {                                  /* ABRKSR       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char ABIF:1;       /*    ABIF      */
                            unsigned char ABIE:1;       /*    ABIE      */
                            }      BIT;                 /*              */
                     }          SR;                     /*              */
               void            *BAR;                    /* BAR          */
               unsigned int     BDR;                    /* BDR          */
};                                                      /*              */
struct st_io {                                          /* struct IO    */
             union {                                    /* PUCR1        */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char B7:1;           /*    Bit 7     */
                          unsigned char B6:1;           /*    Bit 6     */
                          unsigned char B5:1;           /*    Bit 5     */
                          unsigned char B4:1;           /*    Bit 4     */
                          unsigned char   :1;           /*    Bit 3     */
                          unsigned char B2:1;           /*    Bit 2     */
                          unsigned char B1:1;           /*    Bit 1     */
                          unsigned char B0:1;           /*    Bit 0     */
                          }      BIT;                   /*              */
                   }            PUCR1;                  /*              */
             union {                                    /* PUCR5        */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char   :2;           /*    Bit 7,6   */
                          unsigned char B5:1;           /*    Bit 5     */
                          unsigned char B4:1;           /*    Bit 4     */
                          unsigned char B3:1;           /*    Bit 3     */
                          unsigned char B2:1;           /*    Bit 2     */
                          unsigned char B1:1;           /*    Bit 1     */
                          unsigned char B0:1;           /*    Bit 0     */
                          }      BIT;                   /*              */
                   }            PUCR5;                  /*              */
             char               wk1[2];                 /*              */
             union {                                    /* PDR1         */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char B7:1;           /*    Bit 7     */
                          unsigned char B6:1;           /*    Bit 6     */
                          unsigned char B5:1;           /*    Bit 5     */
                          unsigned char B4:1;           /*    Bit 4     */
                          unsigned char   :1;           /*    Bit 3     */
                          unsigned char B2:1;           /*    Bit 2     */
                          unsigned char B1:1;           /*    Bit 1     */
                          unsigned char B0:1;           /*    Bit 0     */
                          }      BIT;                   /*              */
                   }            PDR1;                   /*              */
             union {                                    /* PDR2         */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char   :5;           /*    Bit 7-3   */
                          unsigned char B2:1;           /*    Bit 2     */
                          unsigned char B1:1;           /*    Bit 1     */
                          unsigned char B0:1;           /*    Bit 0     */
                          }      BIT;                   /*              */
                   }            PDR2;                   /*              */
             char               wk2[2];                 /*              */
             union {                                    /* PDR5         */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char B7:1;           /*    Bit 7     */
                          unsigned char B6:1;           /*    Bit 6     */
                          unsigned char B5:1;           /*    Bit 5     */
                          unsigned char B4:1;           /*    Bit 4     */
                          unsigned char B3:1;           /*    Bit 3     */
                          unsigned char B2:1;           /*    Bit 2     */
                          unsigned char B1:1;           /*    Bit 1     */
                          unsigned char B0:1;           /*    Bit 0     */
                          }      BIT;                   /*              */
                   }            PDR5;                   /*              */
             char               wk3;                    /*              */
             union {                                    /* PDR7         */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char   :1;           /*    Bit 7     */
                          unsigned char B6:1;           /*    Bit 6     */
                          unsigned char B5:1;           /*    Bit 5     */
                          unsigned char B4:1;           /*    Bit 4     */
                          }      BIT;                   /*              */
                   }            PDR7;                   /*              */
             union {                                    /* PDR8         */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char B7:1;           /*    Bit 7     */
                          unsigned char B6:1;           /*    Bit 6     */
                          unsigned char B5:1;           /*    Bit 5     */
                          unsigned char B4:1;           /*    Bit 4     */
                          unsigned char B3:1;           /*    Bit 3     */
                          unsigned char B2:1;           /*    Bit 2     */
                          unsigned char B1:1;           /*    Bit 1     */
                          unsigned char B0:1;           /*    Bit 0     */
                          }      BIT;                   /*              */
                   }            PDR8;                   /*              */
             char               wk4;                    /*              */
             union {                                    /* PDRB         */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char B7:1;           /*    Bit 7     */
                          unsigned char B6:1;           /*    Bit 6     */
                          unsigned char B5:1;           /*    Bit 5     */
                          unsigned char B4:1;           /*    Bit 4     */
                          unsigned char B3:1;           /*    Bit 3     */
                          unsigned char B2:1;           /*    Bit 2     */
                          unsigned char B1:1;           /*    Bit 1     */
                          unsigned char B0:1;           /*    Bit 0     */
                          }      BIT;                   /*              */
                   }            PDRB;                   /*              */
             char               wk5[2];                 /*              */
             union {                                    /* PMR1         */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char IRQ3:1;         /*    IRQ3      */
                          unsigned char IRQ2:1;         /*    IRQ2      */
                          unsigned char IRQ1:1;         /*    IRQ1      */
                          unsigned char IRQ0:1;         /*    IRQ0      */
                          unsigned char     :2;         /*              */
                          unsigned char TXD :1;         /*    TXD       */
                          unsigned char TMOW:1;         /*    TMOW      */
                          }      BIT;                   /*              */
                   }            PMR1;                   /*              */
             union {                                    /* PMR5         */
                   unsigned char BYTE;                  /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char     :2;         /*              */
                          unsigned char WKP5:1;         /*    WKP5      */
                          unsigned char WKP4:1;         /*    WKP4      */
                          unsigned char WKP3:1;         /*    WKP3      */
                          unsigned char WKP2:1;         /*    WKP2      */
                          unsigned char WKP1:1;         /*    WKP1      */
                          unsigned char WKP0:1;         /*    WKP0      */
                          }      BIT;                   /*              */
                   }            PMR5;                   /*              */
             char               wk6[2];                 /*              */
             unsigned char      PCR1;                   /* PCR1         */
             unsigned char      PCR2;                   /* PCR2         */
             char               wk7[2];                 /*              */
             unsigned char      PCR5;                   /* PCR5         */
             char               wk8;                    /*              */
             unsigned char      PCR7;                   /* PCR7         */
             unsigned char      PCR8;                   /* PCR8         */
};                                                      /*              */
union un_syscr1 {                                       /* union SYSCR1 */
                unsigned char BYTE;                     /*  Byte Access */
                struct {                                /*  Bit  Access */
                       unsigned char SSBY :1;           /*    SSBY      */
                       unsigned char STS  :3;           /*    STS       */
                       unsigned char NESEL:1;           /*    NESEL     */
                       }      BIT;                      /*              */
};                                                      /*              */
union un_syscr2 {                                       /* union SYSCR2 */
                unsigned char BYTE;                     /*  Byte Access */
                struct {                                /*  Bit  Access */
                       unsigned char SMSEL:1;           /*    SMSEL     */
                       unsigned char LSON :1;           /*    LSON      */
                       unsigned char DTON :1;           /*    DTON      */
                       unsigned char MA   :3;           /*    MA        */
                       unsigned char SA   :2;           /*    SA        */
                       }      BIT;                      /*              */
};                                                      /*              */
union un_iegr1 {                                        /* union IEGR1  */
               unsigned char BYTE;                      /*  Byte Access */
               struct {                                 /*  Bit  Access */
                      unsigned char NMIEG:1;            /*    NMIEG     */
                      unsigned char      :3;            /*              */
                      unsigned char IEG3 :1;            /*    IEG3      */
                      unsigned char IEG2 :1;            /*    IEG2      */
                      unsigned char IEG1 :1;            /*    IEG1      */
                      unsigned char IEG0 :1;            /*    IEG0      */
                      }      BIT;                       /*              */
};                                                      /*              */
union un_iegr2 {                                        /* union IEGR2  */
               unsigned char BYTE;                      /*  Byte Access */
               struct {                                 /*  Bit  Access */
                      unsigned char      :2;            /*              */
                      unsigned char WPEG5:1;            /*    WPEG5     */
                      unsigned char WPEG4:1;            /*    WPEG4     */
                      unsigned char WPEG3:1;            /*    WPEG3     */
                      unsigned char WPEG2:1;            /*    WPEG2     */
                      unsigned char WPEG1:1;            /*    WPEG1     */
                      unsigned char WPEG0:1;            /*    WPEG0     */
                      }      BIT;                       /*              */
};                                                      /*              */
union un_ienr1 {                                        /* union IENR1  */
               unsigned char BYTE;                      /*  Byte Access */
               struct {                                 /*  Bit  Access */
                      unsigned char IENDT:1;            /*    IENDT     */
                      unsigned char IENTA:1;            /*    IENTA     */
                      unsigned char IENWP:1;            /*    IENWP     */
                      unsigned char      :1;            /*              */
                      unsigned char IEN3 :1;            /*    IEN3      */
                      unsigned char IEN2 :1;            /*    IEN2      */
                      unsigned char IEN1 :1;            /*    IEN1      */
                      unsigned char IEN0 :1;            /*    IEN0      */
                      }      BIT;                       /*              */
};                                                      /*              */
union un_irr1 {                                         /* union IRR1   */
              unsigned char BYTE;                       /*  Byte Access */
              struct {                                  /*  Bit  Access */
                     unsigned char IRRDT:1;             /*    IRRDT     */
                     unsigned char IRRTA:1;             /*    IRRTA     */
                     unsigned char      :2;             /*              */
                     unsigned char IRRI3:1;             /*    IRRI3     */
                     unsigned char IRRI2:1;             /*    IRRI2     */
                     unsigned char IRRI1:1;             /*    IRRI1     */
                     unsigned char IRRI0:1;             /*    IRRI0     */
                     }      BIT;                        /*              */
};                                                      /*              */
union un_iwpr {                                         /* union IWPR   */
              unsigned char BYTE;                       /*  Byte Access */
              struct {                                  /*  Bit  Access */
                     unsigned char      :2;             /*              */
                     unsigned char IWPF5:1;             /*    IWPF5     */
                     unsigned char IWPF4:1;             /*    IWPF4     */
                     unsigned char IWPF3:1;             /*    IWPF3     */
                     unsigned char IWPF2:1;             /*    IWPF2     */
                     unsigned char IWPF1:1;             /*    IWPF1     */
                     unsigned char IWPF0:1;             /*    IWPF0     */
                     }      BIT;                        /*              */
};                                                      /*              */
union un_mstcr1 {                                       /* union MSTCR1 */
                unsigned char BYTE;                     /*  Byte Access */
                struct {                                /*  Bit  Access */
                       unsigned char       :1;          /*              */
                       unsigned char MSTIIC:1;          /*    MSTIIC    */
                       unsigned char MSTS3 :1;          /*    MSTS3     */
                       unsigned char MSTAD :1;          /*    MSTAD     */
                       unsigned char MSTWD :1;          /*    MSTWD     */
                       unsigned char MSTTW :1;          /*    MSTTW     */
                       unsigned char MSTTV :1;          /*    MSTTV     */
                       unsigned char MSTTA :1;          /*    MSTTA     */
                       }      BIT;                      /*              */
};                                                      /*              */
#define LVD     (*(volatile struct st_lvd   *)0xF730)   /* LVD   Address*/
#define IIC2    (*(volatile struct st_iic2  *)0xF748)   /* IIC2  Address*/
#define TW      (*(volatile struct st_tw    *)0xFF80)   /* TW    Address*/
#define FLASH   (*(volatile struct st_flash *)0xFF90)   /* FLASH Address*/
#define TV      (*(volatile struct st_tv    *)0xFFA0)   /* TV    Address*/
#define TA      (*(volatile struct st_ta    *)0xFFA6)   /* TA    Address*/
#define SCI3    (*(volatile struct st_sci3  *)0xFFA8)   /* SCI3  Address*/
#define AD      (*(volatile struct st_ad    *)0xFFB0)   /* A/D   Address*/
#define WDT     (*(volatile struct st_wdt   *)0xFFC0)   /* WDT   Address*/
#define ABRK    (*(volatile struct st_abrk  *)0xFFC8)   /* ABRK  Address*/
#define IO      (*(volatile struct st_io    *)0xFFD0)   /* IO    Address*/
#define SYSCR1  (*(volatile union  un_syscr1*)0xFFF0)   /* SYSCR1Address*/
#define SYSCR2  (*(volatile union  un_syscr2*)0xFFF1)   /* SYSCR2Address*/
#define IEGR1   (*(volatile union  un_iegr1 *)0xFFF2)   /* IEGR1 Address*/
#define IEGR2   (*(volatile union  un_iegr2 *)0xFFF3)   /* IEGR2 Address*/
#define IENR1   (*(volatile union  un_ienr1 *)0xFFF4)   /* IENR1 Address*/
#define IRR1    (*(volatile union  un_irr1  *)0xFFF6)   /* IRR1  Address*/
#define IWPR    (*(volatile union  un_iwpr  *)0xFFF8)   /* IWPR  Address*/
#define MSTCR1  (*(volatile union  un_mstcr1*)0xFFF9)   /* MSTCR1Address*/