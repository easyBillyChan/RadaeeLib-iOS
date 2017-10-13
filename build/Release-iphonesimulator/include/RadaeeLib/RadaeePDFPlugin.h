//
//  RadaeePDFPlugin.h
//  RadaeePDFPlugin
//
//  Created by Emanuele Bortolami on 20/06/16.
//  Copyright © 2016 gear.it. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

//#import "PDFObjc.h"

@class PDFDoc;
@class RDPDFViewController;

// define the protocol for the delegate
@protocol RadaeePDFPluginDelegate
// define protocol functions that can be used in any class using this delegate
- (void)willShowReader;
- (void)didShowReader;
- (void)willCloseReader;
- (void)didCloseReader;
- (void)didChangePage:(int)page;
- (void)didSearchTerm:(NSString *)term found:(BOOL)found;
- (void)didTapOnPage:(int)page atPoint:(CGPoint)point;
- (void)didTapOnAnnotationOfType:(int)type atPage:(int)page atPoint:(CGPoint)point;
@end;

//---------------------------------------------------------
/*
 Author: Emanuele
 Date last update: 01/12/16
 Note: Aggiunta la possibilità di nascondere le icone della
 toolbar
 */
//---------------------------------------------------------

@interface RadaeePDFPlugin : NSObject{
    RDPDFViewController *m_pdf;
    
    NSURLConnection *pdfConn;
    NSString *url;
    NSMutableData *receivedData;
    void *buffer;
    
    //colors
    int inkColor;
    int rectColor;
    int underlineColor;
    int strikeoutColor;
    int highlightColor;
    int ovalColor;
    int selColor;
    
    int thumbBackgroundColor;
    int gridBackgroundColor;
    int readerBackgroundColor;
    
    float thumbHeight;
    int gridElementHeight;
    int gridGap;
    int gridMode;
    
    int doubleTapZoomMode;
    
    BOOL firstPageCover;
    BOOL isImmersive;
    
    int bottomBar;
}

@property (nonatomic) int viewMode;

@property (strong, nonatomic) NSString *lastOpenedPath;
@property (strong, nonatomic) UIImage *viewModeImage;
@property (strong, nonatomic) UIImage *searchImage;
@property (strong, nonatomic) UIImage *bookmarkImage;
@property (strong, nonatomic) UIImage *outlineImage;
@property (strong, nonatomic) UIImage *lineImage;
@property (strong, nonatomic) UIImage *rectImage;
@property (strong, nonatomic) UIImage *ellipseImage;
@property (strong, nonatomic) UIImage *printImage;
@property (strong, nonatomic) UIImage *gridImage;
@property (strong, nonatomic) UIImage *deleteImage;
@property (strong, nonatomic) UIImage *doneImage;
@property (strong, nonatomic) UIImage *removeImage;
@property (strong, nonatomic) UIImage *prevImage;
@property (strong, nonatomic) UIImage *nextImage;

@property (nonatomic) BOOL hideViewModeImage;
@property (nonatomic) BOOL hideSearchImage;
@property (nonatomic) BOOL hideBookmarkImage;
@property (nonatomic) BOOL hideBookmarkListImage;
@property (nonatomic) BOOL hideOutlineImage;
@property (nonatomic) BOOL hideLineImage;
@property (nonatomic) BOOL hideRectImage;
@property (nonatomic) BOOL hideEllipseImage;
@property (nonatomic) BOOL hidePrintImage;
@property (nonatomic) BOOL hideGridImage;

@property (nonatomic, weak) UIViewController *viewController;

- (void)pluginInitialize;
- (id)show:(NSString *)file withPassword:(NSString *)password;
- (id)show:(NSString *)file atPage:(int)page withPassword:(NSString *)password readOnly:(BOOL)readOnly autoSave:(BOOL)autoSave;
- (void)activateLicenseWithBundleId:(NSString *)bundleId company:(NSString *)company email:(NSString *)email key:(NSString *)key licenseType:(int)type;
- (id)openFromAssets:(NSString *)file withPassword:(NSString *)password;
- (id)openFromPath:(NSString *)path withPassword:(NSString *)password;
- (NSString *)fileState;
- (int)getPageNumber;
- (int)getPageCount;
- (NSString *)extractTextFromPage:(int)pageNum;
- (BOOL)encryptDocAs:(NSString *)path userPwd:(NSString *)userPwd ownerPwd:(NSString *)ownerPwd permission:(int)permission method:(int)method idString:(NSString *)idString;
- (NSData *)getImageForPage:(int)page;

// Form Manager

- (NSString *)getJSONFormFields;
- (NSString *)getJSONFormFieldsAtPage:(int)page;

- (NSString *)setFormFieldWithJSON:(NSString *)json;

+ (RadaeePDFPlugin *)pluginInit;

+ (NSMutableArray *)loadBookmarkForPdf:(NSString *)pdfName withPath:(BOOL)withPath;

// Bookmarks
+ (NSString *)addToBookmarks:(NSString *)pdfPath page:(int)page label:(NSString *)label;
+ (void)removeBookmark:(int)page pdfPath:(NSString *)pdfPath;
+ (NSString *)getBookmarks:(NSString *)pdfPath;

//Settings

- (void)setPagingEnabled:(BOOL)enabled;
- (void)setDoublePageEnabled:(BOOL)enabled;
- (BOOL)setReaderViewMode:(int)mode;
- (void)toggleThumbSeekBar:(int)mode;
- (void)setColor:(int)color forFeature:(int)feature;
- (void)setThumbnailBGColor:(int)color;
- (void)setReaderBGColor:(int)color;
#if IS_DEMO == 1
- (void)setThumbGridBGColor:(int)color;
- (void)setThumbGridElementHeight:(float)height;
- (void)setThumbGridGap:(float)gap;
- (void)setThumbGridViewMode:(int)mode;
- (void)setDoubleTapZoomMode:(int)mode;
#endif
- (void)setThumbHeight:(float)height;
- (void)setFirstPageCover:(BOOL)cover;
- (void)setImmersive:(BOOL)immersive;

// Delegate

- (void)setDelegate:(id)myDelegate;

- (void)refreshCurrentPage;

@end
