
#include <TStyle.h>
extern TStyle *gStyle;

void stylemacro()
{

  // no border and color white
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameBorderSize(0);

  gStyle->SetDrawBorder(0);

  gStyle->SetTextFont(22);

  // canvas
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasBorderSize(0);
  gStyle->SetCanvasColor(0);

  // pads
  gStyle->SetPadBorderMode(0);             //                                 - default 1
  gStyle->SetPadBorderSize(0);             //                                 - default 1
  gStyle->SetPadColor(kWhite);             // set pad background color        - default 19
  gStyle->SetPadTopMargin(0.05);           //                                 - default 0.1
  gStyle->SetPadBottomMargin(0.15);        //                                 - default 0.1
  gStyle->SetPadLeftMargin(0.15);          //                                 - default 0.1
  gStyle->SetPadRightMargin(0.05);         //                                 - default 0.1
  gStyle->SetPadGridX(kFALSE);             //                                 - default kFALSE
  gStyle->SetPadGridY(kFALSE);             //                                 - default kFALSE
  gStyle->SetPadTickX(kTRUE);              // print ticks on top axis         - default kFALSE
  gStyle->SetPadTickY(kTRUE);              // print ticks on right axis       - default kFALSE

  // histogram title
  gStyle->SetOptTitle(0);
  gStyle->SetTitleBorderSize(0);           // border size of histogram title  - default 2
  gStyle->SetTitleFillColor(kWhite);       // histogram title box fill color  - default 19
  gStyle->SetTitleColor(kBlack, "x");      // histogram x-axis title color    - default kBlack
  gStyle->SetTitleColor(kBlack, "y");      // histogram y-axis title color    - default kBlack
  gStyle->SetTitleTextColor(kBlack);       // histogram title text color      - default kBlack
  gStyle->SetTitleFont(22,"xyz");                // histogram title font            - default 621
  // gStyle->SetTitleFontSize();           // histogram title font size       - default 0

  // histogram axis (Label = numbers, Title = text)
  // gStyle->SetNdivisions(510,"x");
  // gStyle->SetAxisColor(kBlack,"x");
  // gStyle->SetLabelColor("x");
  gStyle->SetLabelFont(22,"xyz");
  // gStyle->SetLabelOffset(0.005,"xyz");  // default: 0.005 (percent of pad width)
  gStyle->SetLabelSize(0.04,"xyz");        // default: 0.04 (percent of pad width)
  // gStyle->SetTickLength("x");           // default: 0.03 (percent of pad width)
//  gStyle->SetTitleOffset(1.30,"x");        // axis title offset                - default: 1.0 (scale factor of default size from label offset and size)
//  gStyle->SetTitleOffset(1.60,"y");        // axis title offset                - default: 1.0 (scale factor of default size from label offset and size)
//  gStyle->SetTitleOffset(1.00,"z");        // axis title offset                - default: 1.0 (scale factor of default size from label offset and size)
  gStyle->SetTitleSize(0.06,"xyz");        // axis title size                  - default: 0.02 (percent of pad width)
  // gStyle->SetTitleFont();               // uses histogram title font
  // gStyle->SetTitleTextColor();          // uses histogram title text color

  // histogram stat box
  gStyle->SetOptStat(0);
  gStyle->SetStatBorderSize(1);            // stat box border size              - default 2 (1 for no shadow)
  gStyle->SetStatColor(0);                 // stat box background color         - default 19
  gStyle->SetStatW(0.25);                  // stat box width
  gStyle->SetStatX(0.9);                   // x position of right top corner    - default 0 (percent of pad)
  gStyle->SetStatY(0.9);                   // y position of right top corner    - default 0 (percent of pad)
  gStyle->SetStatFont(22);                 // stat box font type                - default 62
  // gStyle->SetStatFontSize();            // stat box font size                - default 0
  gStyle->SetStatTextColor(kBlack);        // stat box text color               - default kBlack

  gStyle->SetLineStyleString(2,"24 24"); // set a good length for dashed lines
  gStyle->SetLineStyleString(3,"10 16"); // set a good length for dotted lines

}
