import numpy as np
import numpy.fft as fft
from ROOT import TChain,TH1F
import matplotlib.pyplot as plt
import os,sys

import matplotlib as mpl
mpl.rcParams['text.usetex']=False
#mpl.rcParams['text.latex.unicode']=True
tick_size = 14
fontlabel_size = 16
params = {'axes.labelsize': fontlabel_size, 'text.fontsize': fontlabel_size, 'legend.fontsize': fontlabel_size, 'xtick.labelsize': tick_size, 'ytick.labelsize': tick_size, 'text.usetex': True}

def Autocorrelation(x):
    """
    Compute autocorrelation using FFT
    """
    x = np.asarray(x)
    N = len(x)
    # x = x-x.mean()
    s = fft.fft(x, N*2-1)
    #print s[0]
    #print s[1]
    #print s[2]
    #plt.plot(np.imag(s))
    result = np.real(fft.ifft(s * np.conjugate(s), N*2-1))
    result = result[:N]
    result /= result[0]
    return result

def GetChargeHistArr(filename):
    ch=TChain("data")
    ch.Add(filename)
    ch.SetBranchStatus("*",0)
    ch.SetBranchStatus("qdcch",1)
    ch.SetBranchStatus("temperature",1)  #activate temperature branch
    ch.SetBranchStatus("voltage",1) #activate voltage
    hist=TH1F("charge","hist of qdcbin",4096,0.5,4096.5)
    histTemp = TH1F("temp","hist of temp",500,0,50)
    nevents = ch.GetEntries()
    retvoltage = 0
    for i in range(nevents):
        ch.GetEntry(i)
        if i==0:
            retvoltage = ch.voltage
        hist.Fill(ch.qdcch)
        histTemp.Fill(ch.temperature)
    retTemp = np.array([histTemp.GetMean(),histTemp.GetRMS()])
    retarr = np.array([])
    for i in range(4096):
        retarr = np.append(retarr,hist.GetBinContent(i+1))
    return retarr,retTemp,retvoltage

if __name__ is "__main__":
    filename = sys.argv[1]
    if ".root" in filename:
        histarr,temperature,voltage = GetChargeHistArr(filename)
        fig = plt.figure(figsize=[8,5])
        ax = fig.add_subplot(111)
        ax.plot(histarr,"r-",lw=1.5,label="Charge area spectrum S(q)")
        ax.set_xlabel("Charge [adu]")
        ax.set_ylabel("Entries")
        ax.set_xlim(0,4096)
        ax.legend(loc=1)
        ret = Autocorrelation(histarr)
        locmin = 0
        for i in range(len(ret)-3):
            if ((ret[i+3]>ret[i]) and (ret[i+2]>ret[i]) and (ret[i+1]>ret[i])):
                print i
                locmin=i
                break
        gain = locmin+np.argmax(ret[locmin:])
        print gain
        fig2 = plt.figure(figsize=[8,5])
        ax2 = fig2.add_subplot(111)
        ax2.plot(ret,'b-',lw=1.5,label="Autocorrelation of S(q)")
        ax2.set_xlabel("Charge [adu]")
        ax2.set_ylabel("Autocorrelation of S(q)")
        ax2.set_xlim(0,4096)
        ax2.legend(loc=1)
        plt.show()
