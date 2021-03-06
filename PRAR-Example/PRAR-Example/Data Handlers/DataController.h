//
//  DataController.h
//  PrometAR
//
//  Created by Geoffroy Lesage on 4/12/13.
//  Copyright (c) 2013 Promet Solutions Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SCNetworkReachability.h"
#import "DBController.h"


@class DataController;

@protocol DataControllerDelegate
- (void)gotNearData:(NSArray*)arObjects;
- (void)gotAllData:(NSArray*)arObjects;

- (void)gotUpdatedData;

@end

@interface DataController : NSObject <SCNetworkReachabilityDelegate> {
    DBController *dbController;
    
    // -- Reachability -- //
    BOOL siteIsReachable;
    int tries;
}

@property (assign, nonatomic) id <DataControllerDelegate> delegate;

-(void)getNearARObjects:(CLLocationCoordinate2D)coordinates;
-(void)getAllARObjects:(CLLocationCoordinate2D)coordinates;

-(void)fetchUpdatedARObjects;


@end