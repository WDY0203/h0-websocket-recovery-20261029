
void processEntry entry(void)

{
  undefined8 *in_RDI;
  
  if (in_RDI != (undefined8 *)0x0) {
    if ((void *)*in_RDI != (void *)0x0) {
      operator_delete((void *)*in_RDI);
    }
    operator_delete(in_RDI);
    return;
  }
  return;
}



