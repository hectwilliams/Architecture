#!/usr/bin/env python
import pkg  #lldb library 
import pprint
import os 
import sys 
import os
import lldb

def __lldb_init_module(debugger, dict):
  print('debuggeer init script') 

def test_0 (frame, bp_loc, internal_dict):
  """

    handles breakpoint on function line(i.e. expression )

  """
  fp = frame.GetFP()

  pc = frame.GetPC()

  sp = frame.GetSP() 

  func = frame.GetFunction()
  
  rfp = frame.GetFP() # frame pointer
  
  rip = frame.GetPC() #  instruction pointer ( program counter )

  disassembly = frame.Disassemble()

  is_inlined = frame.IsInlined()

  registers = frame.GetRegisters()

  # vars = frame.GetVariables(get_vars_path)

  # get_vars_path = frame.GetValueForVariablePath()


  print('fp', hex(fp))

  print('pc', hex(pc))

  print('sp', hex(sp))

  print('func', func)

  print('rfp', hex(rfp))

  print('rip', hex(rip))

  print('disassembly', disassembly)

  print ('is_inlined', is_inlined)

  print ('registers', registers)

  # print ('vars', vars)

  # print('get_vars_path', get_vars_path)
  print("------local variables___")
  print(frame.get_locals())
  print("----------------")

  print("------arguments___")
  print(frame.get_arguments())
  print("----------------")

  print("------statics----")
  print(frame.get_statics())
  print("----------------")

def test_1(frame, bp_loc, internal_dict):
  """

    handles breakpoint on function entry 

  """

  pass

