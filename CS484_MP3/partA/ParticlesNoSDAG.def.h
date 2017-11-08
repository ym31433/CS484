




/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::sumReduction_2_closure : public SDAG::Closure {
            int value;


      sumReduction_2_closure() {
        init();
      }
      sumReduction_2_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return value;}
      void pup(PUP::er& __p) {
        __p | value;
        packClosure(__p);
      }
      virtual ~sumReduction_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(sumReduction_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::maxReduction_3_closure : public SDAG::Closure {
            int value;


      maxReduction_3_closure() {
        init();
      }
      maxReduction_3_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return value;}
      void pup(PUP::er& __p) {
        __p | value;
        packClosure(__p);
      }
      virtual ~maxReduction_3_closure() {
      }
      PUPable_decl(SINGLE_ARG(maxReduction_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::iterationEnd_4_closure : public SDAG::Closure {
      

      iterationEnd_4_closure() {
        init();
      }
      iterationEnd_4_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~iterationEnd_4_closure() {
      }
      PUPable_decl(SINGLE_ARG(iterationEnd_4_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::done_5_closure : public SDAG::Closure {
      

      done_5_closure() {
        init();
      }
      done_5_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~done_5_closure() {
      }
      PUPable_decl(SINGLE_ARG(done_5_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Cell::updateNeighbor_2_closure : public SDAG::Closure {
            int iter;
            std::vector<Particle > incoming;


      updateNeighbor_2_closure() {
        init();
      }
      updateNeighbor_2_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return iter;}
            std::vector<Particle > & getP1() { return incoming;}
      void pup(PUP::er& __p) {
        __p | iter;
        __p | incoming;
        packClosure(__p);
      }
      virtual ~updateNeighbor_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(updateNeighbor_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Cell::run_3_closure : public SDAG::Closure {
      

      run_3_closure() {
        init();
      }
      run_3_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~run_3_closure() {
      }
      PUPable_decl(SINGLE_ARG(run_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: readonly CProxy_Main mainProxy;
 */
extern CProxy_Main mainProxy;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_mainProxy(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|mainProxy;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly CProxy_Cell cellProxy;
 */
extern CProxy_Cell cellProxy;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_cellProxy(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|cellProxy;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int particleMultiplier;
 */
extern int particleMultiplier;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_particleMultiplier(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|particleMultiplier;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int charesPerDim;
 */
extern int charesPerDim;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_charesPerDim(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|charesPerDim;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int totalIter;
 */
extern int totalIter;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_totalIter(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|totalIter;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void sumReduction(int value);
void maxReduction(int value);
void iterationEnd();
void done();
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Main::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Main(CkArgMsg* impl_msg);
 */

CkChareID CProxy_Main::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}

void CProxy_Main::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

  CProxy_Main::CProxy_Main(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function

int CkIndex_Main::reg_Main_CkArgMsg() {
  int epidx = CkRegisterEp("Main(CkArgMsg* impl_msg)",
      _call_Main_CkArgMsg, CMessage_CkArgMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkArgMsg::ckDebugPup);
  return epidx;
}


void CkIndex_Main::_call_Main_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  new (impl_obj_void) Main((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void sumReduction(int value);
 */

void CProxy_Main::sumReduction(int value, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int value
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|value;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|value;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_sumReduction_marshall2(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_sumReduction_marshall2(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_sumReduction_marshall2(), impl_msg, &ckGetChareID(),0);
  }
}

void CkIndex_Main::_call_redn_wrapper_sumReduction_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  /*Unmarshall pup'd fields: int value*/
  PUP::fromMem implP(impl_buf);
  /* non two-param case */
  int value; implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->sumReduction(value);
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function

int CkIndex_Main::reg_sumReduction_marshall2() {
  int epidx = CkRegisterEp("sumReduction(int value)",
      _call_sumReduction_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_sumReduction_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_sumReduction_marshall2);

  return epidx;
}


// Redn wrapper registration function

int CkIndex_Main::reg_redn_wrapper_sumReduction_marshall2() {
  return CkRegisterEp("redn_wrapper_sumReduction(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_sumReduction_marshall2, CkMarshallMsg::__idx, __idx, 0);
}


void CkIndex_Main::_call_sumReduction_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int value*/
  PUP::fromMem implP(impl_buf);
  int value; implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->sumReduction(value);
}

int CkIndex_Main::_callmarshall_sumReduction_marshall2(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast< Main *>(impl_obj_void);
  /*Unmarshall pup'd fields: int value*/
  PUP::fromMem implP(impl_buf);
  int value; implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->sumReduction(value);
  return implP.size();
}

void CkIndex_Main::_marshallmessagepup_sumReduction_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int value*/
  PUP::fromMem implP(impl_buf);
  int value; implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("value");
  implDestP|value;
}
PUPable_def(SINGLE_ARG(Closure_Main::sumReduction_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void maxReduction(int value);
 */

void CProxy_Main::maxReduction(int value, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int value
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|value;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|value;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_maxReduction_marshall3(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_maxReduction_marshall3(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_maxReduction_marshall3(), impl_msg, &ckGetChareID(),0);
  }
}

void CkIndex_Main::_call_redn_wrapper_maxReduction_marshall3(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  /*Unmarshall pup'd fields: int value*/
  PUP::fromMem implP(impl_buf);
  /* non two-param case */
  int value; implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->maxReduction(value);
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function

int CkIndex_Main::reg_maxReduction_marshall3() {
  int epidx = CkRegisterEp("maxReduction(int value)",
      _call_maxReduction_marshall3, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_maxReduction_marshall3);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_maxReduction_marshall3);

  return epidx;
}


// Redn wrapper registration function

int CkIndex_Main::reg_redn_wrapper_maxReduction_marshall3() {
  return CkRegisterEp("redn_wrapper_maxReduction(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_maxReduction_marshall3, CkMarshallMsg::__idx, __idx, 0);
}


void CkIndex_Main::_call_maxReduction_marshall3(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int value*/
  PUP::fromMem implP(impl_buf);
  int value; implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->maxReduction(value);
}

int CkIndex_Main::_callmarshall_maxReduction_marshall3(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast< Main *>(impl_obj_void);
  /*Unmarshall pup'd fields: int value*/
  PUP::fromMem implP(impl_buf);
  int value; implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->maxReduction(value);
  return implP.size();
}

void CkIndex_Main::_marshallmessagepup_maxReduction_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int value*/
  PUP::fromMem implP(impl_buf);
  int value; implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("value");
  implDestP|value;
}
PUPable_def(SINGLE_ARG(Closure_Main::maxReduction_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void iterationEnd();
 */

void CProxy_Main::iterationEnd(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  static_cast<void>(impl_e_opts);
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_iterationEnd_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_iterationEnd_void(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_iterationEnd_void(), impl_msg, &ckGetChareID(),0);
  }
}

void CkIndex_Main::_call_redn_wrapper_iterationEnd_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  impl_obj->iterationEnd();
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function

int CkIndex_Main::reg_iterationEnd_void() {
  int epidx = CkRegisterEp("iterationEnd()",
      _call_iterationEnd_void, 0, __idx, 0);
  return epidx;
}


// Redn wrapper registration function

int CkIndex_Main::reg_redn_wrapper_iterationEnd_void() {
  return CkRegisterEp("redn_wrapper_iterationEnd(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_iterationEnd_void, CMessage_CkReductionMsg::__idx, __idx, 0);
}


void CkIndex_Main::_call_iterationEnd_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->iterationEnd();
}
PUPable_def(SINGLE_ARG(Closure_Main::iterationEnd_4_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void done();
 */

void CProxy_Main::done(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  static_cast<void>(impl_e_opts);
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID(),0);
  }
}

void CkIndex_Main::_call_redn_wrapper_done_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  impl_obj->done();
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function

int CkIndex_Main::reg_done_void() {
  int epidx = CkRegisterEp("done()",
      _call_done_void, 0, __idx, 0);
  return epidx;
}


// Redn wrapper registration function

int CkIndex_Main::reg_redn_wrapper_done_void() {
  return CkRegisterEp("redn_wrapper_done(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_done_void, CMessage_CkReductionMsg::__idx, __idx, 0);
}


void CkIndex_Main::_call_done_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->done();
}
PUPable_def(SINGLE_ARG(Closure_Main::done_5_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Main::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(CkArgMsg* impl_msg);
  idx_Main_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Main_CkArgMsg());

  // REG: void sumReduction(int value);
  idx_sumReduction_marshall2();
  idx_redn_wrapper_sumReduction_marshall2();

  // REG: void maxReduction(int value);
  idx_maxReduction_marshall3();
  idx_redn_wrapper_maxReduction_marshall3();

  // REG: void iterationEnd();
  idx_iterationEnd_void();
  idx_redn_wrapper_iterationEnd_void();

  // REG: void done();
  idx_done_void();
  idx_redn_wrapper_done_void();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: array Cell: ArrayElement{
Cell();
void updateNeighbor(int iter, const std::vector<Particle > &incoming);
void run();
Cell(CkMigrateMessage* impl_msg);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Cell::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CProxySection_Cell::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, userData, fragSize);
}

void CProxySection_Cell::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, cb, userData, fragSize);
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Cell();
 */

void CProxyElement_Cell::insert(int onPE, const CkEntryOptions *impl_e_opts)
{ 
   static_cast<void>(impl_e_opts);
  void *impl_msg = CkAllocSysMsg();
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Cell::idx_Cell_void(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void updateNeighbor(int iter, const std::vector<Particle > &incoming);
 */

void CProxyElement_Cell::updateNeighbor(int iter, const std::vector<Particle > &incoming, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int iter, const std::vector<Particle > &incoming
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|iter;
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<Particle > &)incoming;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|iter;
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<Particle > &)incoming;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_updateNeighbor_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run();
 */

void CProxyElement_Cell::run(const CkEntryOptions *impl_e_opts) 
{
  static_cast<void>(impl_e_opts);
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_run_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Cell(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Cell();
 */

CkArrayID CProxy_Cell::ckNew(const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  static_cast<void>(impl_e_opts);
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Cell::idx_Cell_void(), opts);
  return gId;
}

void CProxy_Cell::ckNew(const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  static_cast<void>(impl_e_opts);
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Cell::idx_Cell_void(), _ck_array_creation_cb, opts, impl_msg);
}

CkArrayID CProxy_Cell::ckNew(const int s1, const int s2, const CkEntryOptions *impl_e_opts)
{
  static_cast<void>(impl_e_opts);
  void *impl_msg = CkAllocSysMsg();
  CkArrayOptions opts(s1, s2);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Cell::idx_Cell_void(), opts);
  return gId;
}

void CProxy_Cell::ckNew(const int s1, const int s2, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  static_cast<void>(impl_e_opts);
  void *impl_msg = CkAllocSysMsg();
  CkArrayOptions opts(s1, s2);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Cell::idx_Cell_void(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function

int CkIndex_Cell::reg_Cell_void() {
  int epidx = CkRegisterEp("Cell()",
      _call_Cell_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Cell::_call_Cell_void(void* impl_msg, void* impl_obj_void)
{
  Cell* impl_obj = static_cast<Cell *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  new (impl_obj_void) Cell();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void updateNeighbor(int iter, const std::vector<Particle > &incoming);
 */

void CProxy_Cell::updateNeighbor(int iter, const std::vector<Particle > &incoming, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int iter, const std::vector<Particle > &incoming
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|iter;
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<Particle > &)incoming;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|iter;
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<Particle > &)incoming;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Cell::idx_updateNeighbor_marshall2(),0);
}

// Entry point registration function

int CkIndex_Cell::reg_updateNeighbor_marshall2() {
  int epidx = CkRegisterEp("updateNeighbor(int iter, const std::vector<Particle > &incoming)",
      _call_updateNeighbor_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_updateNeighbor_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_updateNeighbor_marshall2);

  return epidx;
}


void CkIndex_Cell::_call_updateNeighbor_marshall2(void* impl_msg, void* impl_obj_void)
{
  Cell* impl_obj = static_cast<Cell *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int iter, const std::vector<Particle > &incoming*/
  PUP::fromMem implP(impl_buf);
  int iter; implP|iter;
  std::vector<Particle > incoming; implP|incoming;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->updateNeighbor(iter, incoming);
}

int CkIndex_Cell::_callmarshall_updateNeighbor_marshall2(char* impl_buf, void* impl_obj_void) {
  Cell* impl_obj = static_cast< Cell *>(impl_obj_void);
  /*Unmarshall pup'd fields: int iter, const std::vector<Particle > &incoming*/
  PUP::fromMem implP(impl_buf);
  int iter; implP|iter;
  std::vector<Particle > incoming; implP|incoming;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->updateNeighbor(iter, incoming);
  return implP.size();
}

void CkIndex_Cell::_marshallmessagepup_updateNeighbor_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int iter, const std::vector<Particle > &incoming*/
  PUP::fromMem implP(impl_buf);
  int iter; implP|iter;
  std::vector<Particle > incoming; implP|incoming;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("iter");
  implDestP|iter;
  if (implDestP.hasComments()) implDestP.comment("incoming");
  implDestP|incoming;
}
PUPable_def(SINGLE_ARG(Closure_Cell::updateNeighbor_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run();
 */

void CProxy_Cell::run(const CkEntryOptions *impl_e_opts) 
{
  static_cast<void>(impl_e_opts);
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Cell::idx_run_void(),0);
}

// Entry point registration function

int CkIndex_Cell::reg_run_void() {
  int epidx = CkRegisterEp("run()",
      _call_run_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Cell::_call_run_void(void* impl_msg, void* impl_obj_void)
{
  Cell* impl_obj = static_cast<Cell *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->run();
}
PUPable_def(SINGLE_ARG(Closure_Cell::run_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Cell(CkMigrateMessage* impl_msg);
 */

// Entry point registration function

int CkIndex_Cell::reg_Cell_CkMigrateMessage() {
  int epidx = CkRegisterEp("Cell(CkMigrateMessage* impl_msg)",
      _call_Cell_CkMigrateMessage, 0, __idx, 0);
  return epidx;
}


void CkIndex_Cell::_call_Cell_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  call_migration_constructor<Cell> c = impl_obj_void;
  c((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Cell();
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void updateNeighbor(int iter, const std::vector<Particle > &incoming);
 */

void CProxySection_Cell::updateNeighbor(int iter, const std::vector<Particle > &incoming, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int iter, const std::vector<Particle > &incoming
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|iter;
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<Particle > &)incoming;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|iter;
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<Particle > &)incoming;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_updateNeighbor_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run();
 */

void CProxySection_Cell::run(const CkEntryOptions *impl_e_opts) 
{
  static_cast<void>(impl_e_opts);
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_run_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Cell(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Cell::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Cell();
  idx_Cell_void();
  CkRegisterDefaultCtor(__idx, idx_Cell_void());

  // REG: void updateNeighbor(int iter, const std::vector<Particle > &incoming);
  idx_updateNeighbor_marshall2();

  // REG: void run();
  idx_run_void();

  // REG: Cell(CkMigrateMessage* impl_msg);
  idx_Cell_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Cell_CkMigrateMessage());

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerParticlesNoSDAG(void)
{
  static int _done = 0; if(_done) return; _done = 1;
  CkRegisterReadonly("mainProxy","CProxy_Main",sizeof(mainProxy),(void *) &mainProxy,__xlater_roPup_mainProxy);

  CkRegisterReadonly("cellProxy","CProxy_Cell",sizeof(cellProxy),(void *) &cellProxy,__xlater_roPup_cellProxy);

  CkRegisterReadonly("particleMultiplier","int",sizeof(particleMultiplier),(void *) &particleMultiplier,__xlater_roPup_particleMultiplier);

  CkRegisterReadonly("charesPerDim","int",sizeof(charesPerDim),(void *) &charesPerDim,__xlater_roPup_charesPerDim);

  CkRegisterReadonly("totalIter","int",sizeof(totalIter),(void *) &totalIter,__xlater_roPup_totalIter);

/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void sumReduction(int value);
void maxReduction(int value);
void iterationEnd();
void done();
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: array Cell: ArrayElement{
Cell();
void updateNeighbor(int iter, const std::vector<Particle > &incoming);
void run();
Cell(CkMigrateMessage* impl_msg);
};
*/
  CkIndex_Cell::__register("Cell", sizeof(Cell));

}
extern "C" void CkRegisterMainModule(void) {
  _registerParticlesNoSDAG();
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Main::virtual_pup(PUP::er &p) {
    recursive_pup<Main >(dynamic_cast<Main* >(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Cell::virtual_pup(PUP::er &p) {
    recursive_pup<Cell >(dynamic_cast<Cell* >(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
