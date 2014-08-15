<?php
/**
 * @file
 * This template handles the layout of oa_well.
 */
$path = drupal_get_path('module', 'cedi_styles');

if (isset($settings['well'])) {
  // Make sure we set the right border width and color.
  if (!isset($settings['well']['color'])) {
    $color = 'lightgrey';
  }
  elseif ($settings['well']['color'] == 'other') {
    $color = $settings['well']['custom_color'];
  }
  else {
    $color = $settings['well']['color'];
  }
}
else {
  $color = 'lightgrey';
}

?>
<!-- We only want to add the title here if the settings checkbox is not checked. -->
<?php if ($title && !$settings['well']['include_title']): ?>
  <h4 class="pane-title"><?php print $title; ?></h4>
  <hr>
<?php endif; ?>
<div class="cedi-well style-region
  <?php if (!empty($settings['shadow'])): ?> box-shadow<?php endif; ?>
  <?php if (!empty($settings['well']['well_modifier'])): print $settings['well']['well_modifier']; endif; ?>"
  <?php if (!empty($settings['add_border'])): ?>
    <?php include './'. $path .'/plugins/styles/cedi_border/cedi-border.tpl.php' ;?>
  <?php endif; ?> style="background-color: <?php print $color; ?>">
  <!-- We add the title here if it has been selected -->
  <?php if ($title && $settings['well']['include_title']): ?>
    <h4 class="pane-title"><?php print $title; ?></h4>
    <hr>
  <?php endif; ?>
  <?php print $content; ?>
</div>

