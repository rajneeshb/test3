<?php
// $Id: node.tpl.php,v 1.10 2009/11/02 17:42:27 johnalbin Exp $

/**
 * @file
 * Theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: Node body or teaser depending on $teaser flag.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $display_submitted: whether submission information should be displayed.
 * - $links: Themed links like "Read more", "Add new comment", etc. output
 *   from theme_links().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 *   The following applies only to viewers who are registered users:
 *   - node-by-viewer: Node is authored by the user currently viewing the page.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $build_mode: Build mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $build_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * The following variables are deprecated and will be removed in Drupal 7:
 * - $picture: This variable has been renamed $user_picture in Drupal 7.
 * - $submitted: Themed submission information output from
 *   theme_node_submitted().
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see zen_preprocess()
 * @see zen_preprocess_node()
 * @see zen_process()
 */

?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix">
  <?php print $user_picture; ?>

  <?php if (!$page): ?>
    <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>

  <?php if ($unpublished): ?>
    <div class="unpublished"><?php print t('Unpublished'); ?></div>
  <?php endif; ?>

  <?php if ($display_submitted || $terms): ?>
    <div class="meta">
      <?php if ($display_submitted): ?>
        <span class="submitted">
          <?php
            $user_profile = content_profile_load('profile', $node->uid);
            if ( !empty($user_profile) ) {
              $name = implode(' ', array($user_profile->field_first_name[0]['value'], $user_profile->field_last_name[0]['value']));
              $name = l( $name, drupal_get_path_alias('user/' . $node->uid) );
            }
            print t('Submitted by !username on !datetime',
              array('!username' => $name, '!datetime' => $date));
          ?>
        </span>
      <?php endif; ?>

      <?php if ($terms): ?>
        <div class="terms terms-inline"><?php print $terms; ?></div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php
/**
*
* template for viewing user profile
* add the "Roles" field
*
*/
    $user_role = user_load(array('uid' => $user_profile->uid));
  ?>
  <div class="content">
    <fieldset class="fieldgroup personal-information"><legend>Personal Information</legend>

      <?php if ( user_access('view field_court_location_groups') && !empty($user_profile->field_court_location_groups) ) : ?>
        <div class="field field-type-nodereference field-field-court-location-groups">
          <div class="field-label">Court Location Groups:&nbsp;</div>
          <div class="field-items">
            <?php
              foreach($user_profile->field_court_location_groups as $group_loc){
                $group_loc_id = $group_loc['nid'];
                $court = node_load($group_loc);
            ?>
            <div class="field-item odd">
               <a href="/node/<?php echo $group_loc_id; ?>"><?php echo $court->field_providergroupname[0]['value'];?></a>
            </div>
            <?php } ?>
          </div>
        </div>
      <?php endif; ?>

      <div class="field field-type-text field-field-first-name">
        <div class="field-items">
          <div class="field-item odd">
            <div class="field-label-inline-first">
                First Name:&nbsp;
            </div>
            <?php echo $user_profile->field_first_name[0]['value']; ?>
          </div>
        </div>
      </div>

      <div class="field field-type-text field-field-last-name">
        <div class="field-items">
          <div class="field-item odd">
            <div class="field-label-inline-first">
              Last Name:&nbsp;
            </div>
            <?php echo $user_profile->field_last_name[0]['value']; ?>
          </div>
        </div>
      </div>

      <?php if ( user_access('view field_court_location_groups') ) : ?>
        <div class="field field-type-text field-field-role">
          <div class="field-items">
            <div class="field-item odd">
              <div class="field-label-inline-first">
                Role(s):&nbsp;
              </div>
              <?php
                foreach ($user_role->roles as $role) {
                  $role = t(" (%role)", array('%role' => $role,));
                  echo $role;
                } 
             ?>
             </div>
          </div>
        </div>
      <?php endif; ?>

      <?php if ( user_access('view field_address') && !empty($user_profile->field_daytime_phone[0]['value']) ) : ?>
        <div class="field field-type-text field-field-address">
          <div class="field-items">
            <div class="field-item odd">
              <div class="field-label-inline-first">
                Daytime Phone:&nbsp;
              </div>
                <?php echo $user_profile->field_daytime_phone[0]['value']; ?>
            </div>
          </div>
        </div>
      <?php endif; ?>

      <?php if ( user_access('view field_address') && !empty($user_profile->field_company_firm[0]['value']) ) : ?>
        <div class="field field-type-text field-field-address">
          <div class="field-items">
            <div class="field-item odd">
              <div class="field-label-inline-first">
                Company/Firm:&nbsp;
              </div>
                <?php echo $user_profile->field_company_firm[0]['value']; ?>
            </div>
          </div>
        </div>
      <?php endif; ?>

      <?php if ( user_access('view field_address') && !empty($user_profile->field_address[0]['value']) ) : ?>
        <div class="field field-type-text field-field-address">
          <div class="field-items">
            <div class="field-item odd">
              <div class="field-label-inline-first">
                Address:&nbsp;
              </div>
                <p><?php echo $user_profile->field_address[0]['value']; ?></p>
            </div>
          </div>
        </div>
      <?php endif; ?>

      <?php if ( user_access('view field_address') && !empty($user_profile->field_comments[0]['value']) ) : ?>
        <div class="field field-type-text field-field-address">
          <div class="field-items">
            <div class="field-item odd">
              <div class="field-label-inline-first">
                Additional Information:&nbsp;
              </div>
                <p><?php echo $user_profile->field_comments[0]['value']; ?></p>
            </div>
          </div>
        </div>
      <?php endif; ?>

    </fieldset>
  </div>

  <?php print $links; ?>
</div> <!-- /.node -->
